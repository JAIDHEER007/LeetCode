# LC 46
# Runtime: 44ms
# FT: 45.02%
# Memory Usage: 14.3mb
# LT: 90.9%

def permute(nums):
    result = []
       
    def findPermutations(permutation, visited):
        
        # Base Case
        if len(permutation) == len(nums):
            result.append(permutation)
            return
            
        # Recursive Case
        for i in range(len(nums)):
            if not visited[i]:
                permutation.append(nums[i])
                visited[i] = True
                
                findPermutations(permutation[:], visited[:])
                
                permutation.pop()
                visited[i] = False
                    
    
    findPermutations([], [False for _ in range(len(nums))])
    
    return result

if __name__ == '__main__':
    nums = list(map(int, input().split()))
    
    result = permute(nums)
    
    for row in result:
        for element in row:
            print(element, end = ' ')
        print('')