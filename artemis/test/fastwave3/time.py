# -*- coding: utf-8 -*-
#gridnums = [125,250,500,1000,2000,4000,8000,16000,32000]
gridnums = [125,250,500,1000,2000,4000,8000,16000,32000]
for grid in gridnums:
    filename =  "grid"+ str(grid) +"_time.txt"
    with open(filename, 'r') as file:
        lines = file.readlines()

    min_time = float('inf') 
    min_grid = '' 

    for line in lines:
        elements = line.strip().split(',') 
        time = float(elements[-1])  
        gridnum = int(elements[-2])  
        if gridnum == grid and time > 0.5 and time < min_time:
            min_time = time
            min_grid = gridnum
    print(min_grid)
    print(min_time)
    with open('time.txt', 'a') as file:
        file.write("{},{}".format(min_grid, min_time))
        file.write('\n')