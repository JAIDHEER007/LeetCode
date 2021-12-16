# LC 34
# Find First and Last Position of Element in Sorted Array

# RT: 134 ms
# FT: 9.83 %

# MUL 15.3 MB
# LT: 83.2%

def binarySearch(nums, key):
    
    start = 0
    end = len(nums) - 1
    
    while start <= end:
        mid = end + (start - end) // 2
        
        if nums[mid] == key: 
            return mid 
        elif nums[mid] < key:
            start = mid + 1
        else:
            end = mid - 1
            
    return -1
    
def searchRange(nums, target):
    index = binarySearch(nums, target)
    
    if index == -1:
        return [-1, -1]
        
    # Left Index
    left = index
    while (left >= 0) and (nums[left] == target):
        left -= 1

    # Right Index
    right = index
    while (right < len(nums)) and (nums[right] == target):
        right += 1
        
    return [(left + 1), (right - 1)]

if __name__ == '__main__':
    
    nums = list(map(int, input().split()))
    target = int(input())
    
    start, end = searchRange(nums, target)
    
    print(start, end)