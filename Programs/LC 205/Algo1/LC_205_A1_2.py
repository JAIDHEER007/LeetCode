import os
import sys

cwd = sys.path[0]

# Implement the solution class 
# With the given methods
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        umap, mapped = {}, {}

        for (x, y) in zip(s, t):
            if y not in mapped:
                if x in umap: return False
                umap[x] = y
                mapped[y] = True
            elif x not in umap or umap[x] != y:
                return False
            
        return True


if __name__ == '__main__': 
    nInputs = 5

    # Creating a Solutuion Object
    solObj = Solution()

    for i in range(1, nInputs + 1): 
        fname = "input{number}.txt"
        fpath = os.path.join(cwd, '..', fname.format(number = i))
        print(fpath)
        
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