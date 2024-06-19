def findMin(nums: list) -> int:
    if len(nums) == 1:
        return nums[0]
        
    l, r = 0, len(nums) - 1
    minVal = 10**5
    if nums[r] > nums[0]:
        return nums[0]
    while l <= r:
        mid = (l + r) // 2
        # print(nums[mid])
        minVal = min(minVal, nums[mid])
        if nums[mid] > nums[mid + 1]:
            return nums[mid + 1]
    
        if nums[mid - 1] > nums[mid]:
            return nums[mid]

        if nums[mid] > nums[0]:
            l = mid + 1
        else:
            r = mid - 1
    return minVal

if __name__ == '__main__':
    nums = [3,4,5,1,2]
    # nums = [4,5,6,7,0,1,2]
    # nums = [5,1,2,3,4]
    # nums = [11, 12, 13, 14]
    print(findMin(nums))