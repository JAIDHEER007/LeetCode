import os
cwd = os.path.dirname(__file__)

def convert(s: str, numRows: int) -> str:
    if numRows == 1: return s
    
    rows = [''] * numRows

    rowNum, increasing = 1, True

    for ch in s:
        if rowNum == 1: increasing = True
        elif rowNum == numRows: increasing = False

        rows[rowNum - 1] += ch
        rowNum = (rowNum + 1) if increasing else (rowNum - 1)
    
    return ''.join(rows)

if __name__ == '__main__': 
    nInputs = 5

    for i in range(1, nInputs + 1): 
        fname = "input{number}.txt"
        fpath = os.path.join(cwd, fname.format(number = i))
        
        print("======== TestCase {number} ========".format(number = i))
        try: 
            with open(fpath, "r") as fileHandle: 
                #  ===== START =====
                s = fileHandle.readline().strip()
                numRows = int(fileHandle.readline().strip())

                print(convert(s, numRows))

                #  ===== END =====
        except FileNotFoundError:
            print("Cannot Open the test case")
            break