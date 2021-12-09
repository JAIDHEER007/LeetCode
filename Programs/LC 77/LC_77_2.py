# LC 77
# Runtime: 479ms
# FT: 51.27%
# Memeory Usage: 15.7mb
# LT: 53.80%

def combine(n: int, k: int):
    result = []
    
    def findCombinations(arr = [], currNum = 1):
        
        # Base Case
        if len(arr) == k:
            result.append(arr)
            return 
            
        # Recursive Case
        for i in range(currNum, (n + 1)):
            arr.append(i)
            findCombinations(arr[:], (i + 1))
            arr.pop()
    
    findCombinations()
    return result
    

if __name__ == '__main__':
    n, k = list(map(int, input().split()))
    
    result = combine(n ,k)
    
    for row in result:
        for element in row:
            print(element, end = ' ')
        
        print('')