import os
import sys

from cv2 import transform
cwd = sys.path[0]

# Implement the solution class 
# With the given methods
class Solution:
    def transformString(s):
        n = len(s)
        transformArr = [0] * n
        indexDict = {}

        for i in range(n):
            if s[i] not in indexDict:
                indexDict[s[i]] = i

            transformArr[i] = indexDict[s[i]]

        return transformArr
    
    def isIsomorphic(self, s: str, t: str) -> bool:
        st = Solution.transformString(s)
        tt = Solution.transformString(t)

        for (x, y) in zip(st, tt):
            if x != y: return False
        
        return True

if __name__ == '__main__': 
    nInputs = 5

    # Creating a Solution Object
    solObj = Solution()

    for i in range(1, nInputs + 1): 
        fname = "input{number}.txt"
        fpath = os.path.join(cwd, '..', fname.format(number = i))
        
        print("======== TestCase {number} ========".format(number = i))
        try: 
            with open(fpath, "r") as fileHandle: 
                #  ===== START =====
                s = fileHandle.readline().strip()
                t = fileHandle.readline().strip()

                print(s)
                print(t)
                print(solObj.isIsomorphic(s, t))

                #  ===== END =====
        except FileNotFoundError:
            print("Cannot Open the test case")
            break