import os
import csv
cwd = os.path.dirname(__file__)

def champagneTower(poured: int, query_row: int, query_glass: int):
    arr = [[0.0 for _ in range(100)] for _ in range(100)]

    arr[0][0] = poured
    for i in range(99): 
        for j in range(99): 
            if arr[i][j] == 1e-9:
                break; 
            remaining = arr[i][j] - 1.0
            if arr[i][j] > 1.0:
                arr[i + 1][j] += remaining / 2.0 
                arr[i + 1][j + 1] += remaining / 2.0 
            
                 

    return 1 if arr[query_row][query_glass] > 1 else arr[query_row][query_glass] 


if __name__ == '__main__': 
    nInputs = 4

    for i in range(1, nInputs + 1): 
        fname = "input{number}.txt"
        fpath = os.path.join(cwd, fname.format(number = i))
        
        print("======== TestCase {number} ========".format(number = i))
        try: 
            with open(fpath, "r") as fileHandle: 
                #  ===== START =====
                poured = int(fileHandle.readline().strip())
                query_row = int(fileHandle.readline().strip())
                query_glass = int(fileHandle.readline().strip())

                print(champagneTower(poured, query_row, query_glass))

                #  ===== END =====
        except FileNotFoundError:
            print("Cannot Open the test case")
            break