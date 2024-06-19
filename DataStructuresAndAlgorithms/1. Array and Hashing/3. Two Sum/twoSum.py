from collections import Counter

def twoSum(nums: list, target: int) -> list:
    counts = Counter(nums)
    for i in range(len(nums)):
        counts[nums[i]] -= 1
        anVal = target - nums[i]
        if anVal in counts and counts[anVal] > 0:
            return [i, nums.index(anVal, i+1)]

if __name__ == "__main__":
    # nums = [3,2,4]
    # target = 6
    nums = [2,7,11,15]
    target = 9
    print(twoSum(nums, target))