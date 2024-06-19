def twoSum(numbers: list, target: int) -> list:
    l, r = 0, len(numbers) - 1
    while l < r:
        curSum = numbers[l] + numbers[r]
        
        if curSum > target:
            r -= 1
        elif curSum < target:
            l += 1
        else:
            return [l + 1, r + 1]
    # def binary_search(target, l, r):
    #         while l <= r:
    #             m = l + ((r - l) // 2)
    #             if numbers[m] > target:
    #                 r = m - 1
    #             elif numbers[m] < target:
    #                 l = m + 1
    #             else:
    #                 return m
    #         return -1
    #     for i in range(len(numbers)):
    #         newTarget = target - numbers[i]
    #         j = binary_search(newTarget, i + 1, len(numbers) - 1)
    #         if j == -1 : continue
    #         else: return [i+1, j+1]

if __name__ == '__main__':
    numbers = [2,7,11,15]
    target = 9
    print(twoSum(numbers, target))
        