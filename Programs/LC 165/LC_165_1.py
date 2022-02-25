# Runtime: 32 ms
# Faster Than: 83.77%
# Memory Usage: 14 MB
# Less Than: 52.71%

import os
cwd = os.path.dirname(__file__)

def compareVersion(version1: str, version2: str) -> int:
    version1 = list(map(int, version1.strip().split('.')))
    version2 = list(map(int, version2.strip().split('.')))

    i, j, diff = 0, 0, 0
    lenV1, lenV2 = len(version1), len(version2)

    while (i < lenV1) and (j < lenV2): 
        if version1[i] > version2[j]: 
            diff += 1
        elif version1[i] < version2[j]:
            diff -= 1
        diff *= 10

        i += 1
        j += 1
    
    while i < lenV1: 
        if version1[i] > 0: 
            diff += 1
        diff *= 10
        i += 1
    
    while j < lenV2: 
        if version2[j] > 0: 
            diff -= 1
        diff *= 10
        j += 1
    
    if diff < 0: return -1
    elif diff > 0: return 1

    return 0


if __name__ == '__main__': 
    nInputs = 5

    for i in range(1, nInputs + 1): 
        fname = "input{number}.txt"
        fpath = os.path.join(cwd, fname.format(number = i))
        
        print("======== TestCase {number} ========".format(number = i))
        try: 
            with open(fpath, "r") as fileHandle: 
                #  ===== START =====
                
                version1 = fileHandle.readline().strip()
                version2 = fileHandle.readline().strip()

                print(compareVersion(version1, version2))

                #  ===== END =====
        except FileNotFoundError:
            print("Cannot Open the test case")
            break