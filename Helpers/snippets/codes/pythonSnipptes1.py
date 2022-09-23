import os
import sys
cwd = sys.path[0]

# Implement the solution class 
# With the given methods
class Solution:
    pass 

if __name__ == '__main__': 
    nInputs = 5

    for i in range(1, nInputs + 1): 
        fname = "input{number}.txt"
        fpath = os.path.join(cwd, fname.format(number = i))
        
        print("======== TestCase {number} ========".format(number = i))
        try: 
            with open(fpath, "r") as fileHandle: 
                #  ===== START =====
                pass

                #  ===== END =====
        except FileNotFoundError:
            print("Cannot Open the test case")
            break