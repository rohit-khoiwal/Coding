def containsDuplicate(nums: list) -> bool:
        uniVals = set()
        for num in nums:
            if num in uniVals: return True
            uniVals.add(num)
        return False

if __name__=="__main__":
    '''
    Test Cases
    [1,2,3,1]
    [1,2,3,4]
    [1,1,1,3,3,4,3,2,4,2]
    '''
    nums = [1,2,3,4]
    print(containsDuplicate(nums))