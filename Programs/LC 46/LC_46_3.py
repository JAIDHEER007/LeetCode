# LC 46 
# Using Inbuilt Functions
# Runtime: 36ms
# FT: 89.66%
# Memeory Usage: 14.5mb
# LT: 45.88%

import itertools

def permute(nums):
    return [list(seq) for seq in itertools.permutations(nums)]

if __name__ == '__main__':
    nums = list(map(int, input().split()))
    
    result = permute(nums)
    
    for row in result:
        for element in row:
            print(element, end = ' ')
        print('')