# LC 35
# Search Insert Possition

def searchInsert(nums, target):
    start = 0
    end = len(nums) - 1
    
    while start <= end:
        mid = end + (start - end) // 2
        
        if nums[mid] == target: return mid
        elif nums[mid] < target: start = mid + 1
        else: end = mid - 1
        
    return end + 1

if __name__ == '__main__':
    nums = list(map(int, input().split()))
    target = int(input())
    
    print(searchInsert(nums, target))