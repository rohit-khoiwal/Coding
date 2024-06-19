def productExceptSelf(nums: list) -> list:
    results = [1]*len(nums)
    prefix = 1
    postfix = 1
    for i in range(len(nums)):
        results[i] *= prefix
        results[len(nums) -i - 1] *= postfix
        prefix *= nums[i]
        postfix *= nums[len(nums) - i - 1]
    return results
    

if __name__ == "__main__":
    # solve the problem in O(n) time
    # product of array except self

    nums = [1,2,3,4]
    print(productExceptSelf(nums))