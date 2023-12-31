import itertools
from functools import reduce
import os
import re
import sys
import pickle
import subprocess
maxThreadsPerBlockLg2 = 10# 512 
maxUnrollFactorLg2 = 2# 4 
dimensions = []

def compileAndGetResults(cfg):
    args = cfgToCommandLine(cfg).split(' ')


def FilterParams(spaceVector):
    _, blockDim, unrollDim = spaceVector
    """ can't stream and unroll in same dimension """
    if reduce(lambda x, y: x * y, unrollDim) > 8:
        return False
    return True

def cfgToCommandLine(spaceVector):
    prefetch, blockDim, unrollDim = spaceVector
    cmd = ''
    if blockDim:
        cmd += "--blockdim x={0},y={1},z={2}".format(*blockDim)
    if unrollDim:
        cmd += " --unroll " + ",".join(
          [x + '=' + str(y) for (x, y) in zip(dimensions, unrollDim)])
    if prefetch:
        cmd += " --prefetch"
    return cmd

def cfgToString(spaceVector):
    prefetch, blockDim, unrollDim = spaceVector
    cmd = ''
    if blockDim:
        cmd += "bx{0}y{1}z{2}".format(*blockDim)
    if unrollDim:
        cmd += "u" + "".join(
          [x + str(y) for (x, y, z) in zip(dimensions, unrollDim)])
        #cmd += " --unroll " + ",".join(
        #[dimensions[i/2] if not i%2 else str(unrollDim[i/2])
        #  for i in range(2 * len(unrollDim))])
    if prefetch:
        cmd += "p"
    return cmd

def searchSpace(dslFiles):
    assert(len(dslFiles) == 2)
    global dimensions
    with open(os.path.expanduser(dslFiles[1])) as dslFile:
        for line in dslFile:
            m = re.match(r"iterator (.*);", line)
            if m:
                dimensions = [i.strip() for i in m.group(1).split(',')] #k, j, i
                break
    # can't be 2: as the size would be lesser when considering distance -1 and so on
    # can't be 4: there is floating point error
    blockDim = itertools.product([2**i for i in range(2, maxThreadsPerBlockLg2)],
                                 repeat=len(dimensions))
    unrollDim = itertools.product([2**i for i in range(maxUnrollFactorLg2)],
     repeat=len(dimensions))
    for i in itertools.ifilter(FilterParams, itertools.product(
      [False, True], # prefetch?
      itertools.ifilter(lambda (x, y, z): x * y * z <=
        2 ** (maxThreadsPerBlockLg2 - 1) and x * y * z >= 16,
        blockDim), # blockDim
      unrollDim, # unrollFactors
     )):
        config = cfgToCommandLine(i)
        cmd = " ".join(["bash run.sh", dslFiles[1], \
          config, "--ndim L=320,M=320,N=320"])
        output = subprocess.check_output(cmd, shell=True)
        print(config + ": " + output)
if __name__ == '__main__':
    searchSpace(sys.argv)
