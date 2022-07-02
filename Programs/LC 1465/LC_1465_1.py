import os
cwd = os.path.dirname(__file__)

def maxArea(h: int, w: int, horizontalCuts: list[int], verticalCuts: list[int]) -> int:
    # Sorting horizontalCuts and verticalCuts
    horizontalCuts.sort()
    verticalCuts.sort()

    # Adding the verticalEnd and horizontalEnd
    horizontalCuts.append(h)
    verticalCuts.append(w)

    start = 0
    # Finding the maxVcut
    maxVcut = 0
    for cut in verticalCuts:
        maxVcut = max(maxVcut, (cut - start))
        start = cut
    
    start = 0
    # Finding the maxHcut
    maxHcut = 0
    for cut in horizontalCuts:
        maxHcut = max(maxHcut, (cut - start))
        start = cut

    return (maxVcut * maxHcut) % 1000000007
    

if __name__ == '__main__': 
    nInputs = 4

    for i in range(1, nInputs + 1): 
        fname = "input{number}.txt"
        fpath = os.path.join(cwd, fname.format(number = i))
        
        print("======== TestCase {number} ========".format(number = i))
        try: 
            with open(fpath, "r") as fileHandle: 
                #  ===== START =====
                h, w = list(map(int, fileHandle.readline().split()[:2]))
                
                hcCnt = int(fileHandle.readline())
                horizontalCuts = list(map(int, fileHandle.readline().split()[:hcCnt]))

                vcCnt = int(fileHandle.readline())
                verticalCuts = list(map(int, fileHandle.readline().split()[:vcCnt]))

                print(maxArea(h, w, horizontalCuts, verticalCuts))

                #  ===== END =====
        except FileNotFoundError:
            print("Cannot Open the test case")
            break