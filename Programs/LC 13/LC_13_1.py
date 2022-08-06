import os
cwd = os.path.dirname(__file__)

class Solution:
    def romanToInt(self, s: str) -> int:
        romanNumerals = {
            'M': 1000, 
            'D': 500, 
            'C': 100, 
            'L': 50, 
            'X': 10, 
            'V': 5, 
            'I': 1
        }

        sum, prevNum = 0, -1

        for romanNumeral in s:
            rn = romanNumerals[romanNumeral]

            if prevNum == -1:
                sum = rn
            else:
                if prevNum < rn:
                    sum -= prevNum
                    sum += (rn - prevNum)
                else:
                    sum += rn

            prevNum = rn
        
        return sum

if __name__ == '__main__': 
    nInputs = 6
    solObj = Solution()

    for i in range(1, nInputs + 1): 
        fname = "input{number}.txt"
        fpath = os.path.join(cwd, fname.format(number = i))
        
        print("======== TestCase {number} ========".format(number = i))
        try: 
            with open(fpath, "r") as fileHandle: 
                #  ===== START =====
                s = fileHandle.readline()

                print(solObj.romanToInt(s))

                #  ===== END =====
        except FileNotFoundError:
            print("Cannot Open the test case")
            break