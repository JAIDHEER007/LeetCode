import os
cwd = os.path.dirname(__file__)

def intToRoman(num: int) -> str:
    romanNumerals = {
        1: 'I', 
        5: 'V', 
        10: 'X', 
        50: 'L', 
        100: 'C', 
        500: 'D', 
        1000: 'M'
    }

    result, tens = "", 1

    while num != 0:
        num, rem = divmod(num, 10)

        if rem != 0:
            romanDigit = ""
            if rem == 4:
                romanDigit = (romanNumerals[tens] + romanNumerals[5 * tens])
            elif rem == 9:
                romanDigit = (romanNumerals[tens] + romanNumerals[10 * tens])
            else:
                centerPoint = 5 * tens

                if (rem * tens) < centerPoint:
                    romanDigit = (romanNumerals[tens] * rem)
                else:
                    romanDigit = (romanNumerals[centerPoint] + (romanNumerals[tens] * (rem - 5)))

            result = romanDigit + result
        
        tens *= 10

    return result


if __name__ == '__main__': 
    nInputs = 6

    for i in range(1, nInputs + 1): 
        fname = "input{number}.txt"
        fpath = os.path.join(cwd, fname.format(number = i))
        
        print("======== TestCase {number} ========".format(number = i))
        try: 
            with open(fpath, "r") as fileHandle: 
                #  ===== START =====
                n = int(fileHandle.readline().strip())

                print(n)
                print(intToRoman(n))

                #  ===== END =====
        except FileNotFoundError:
            print("Cannot Open the test case")
            break