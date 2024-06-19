def searchMatrix(self, matrix: list, target: int) -> bool:
    def binary_search(nums):
        l = 0
        r = len(nums) - 1
        while l <= r:
            mid = (l + r) // 2
            if nums[mid] == target:
                return True
            elif nums[mid] < target:
                l = mid + 1
            else:
                r = mid - 1
        return False
        
    l = 0
    r = len(matrix) - 1
    while l <= r:
        mid = (l + r) // 2
        if matrix[mid][0] <= target and target <= matrix[mid][-1]:
            return binary_search(matrix[mid])
        
        elif matrix[mid][0] > target:
            r = mid - 1
        else:
            l = mid + 1

if __name__ == '__main__':
    matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]]
    target = 3
    searchMatrix(matrix, target)