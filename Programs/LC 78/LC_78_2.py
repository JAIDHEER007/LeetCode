# LC 78
# Subsets

def subsets(nums):
    n = len(nums)
    
    result = []
    
    for i in range(1 << n):
        combination = []
        j = i
        
        for element in nums:
            if (j & 1):
                combination.append(element)
                
            j >>= 1
        
        result.append(combination)
        
    
    return result; 

if __name__ == '__main__':
    nums = list(map(int, input().split()))
    result = subsets(nums)
    
    for row in result:
        print(row)