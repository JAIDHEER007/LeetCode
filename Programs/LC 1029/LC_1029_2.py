import os
cwd = os.path.dirname(__file__)

def twoCitySchedCost(costs: list[list[int]]) -> int:
    n = len(costs)

    costs.sort(key = lambda cost: cost[1] - cost[0])

    minCost = 0
    for i in range(n):
        minCost += costs[i][1 if i < (n // 2) else 0]

    return minCost

if __name__ == '__main__': 
    nInputs = 3

    for i in range(1, nInputs + 1): 
        fname = "input{number}.txt"
        fpath = os.path.join(cwd, fname.format(number = i))
        
        print("======== TestCase {number} ========".format(number = i))
        try: 
            with open(fpath, "r") as fileHandle: 
                #  ===== START =====
                data = fileHandle.readlines()
                data = [inp.strip() for inp in data]

                costs = [list(map(int, inp.split())) for inp in data]

                print(twoCitySchedCost(costs))
                #  ===== END =====
        except FileNotFoundError:
            print("Cannot Open the test case")
            break