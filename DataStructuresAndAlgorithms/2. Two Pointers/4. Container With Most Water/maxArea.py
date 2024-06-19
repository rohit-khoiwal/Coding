def maxArea(height: list) -> int:
    left = 0
    right = len(height) - 1
    maxWater = 0
    while left <= right:
        newWater = (right - left)*min(height[left], height[right])
        if newWater > maxWater:
            maxWater = newWater
        if height[left] <= height[right]:
            left += 1
        else:
            right -= 1
    return maxWater

if __name__ == '__main__':
    heights = [1,8,6,2,5,4,8,3,7]
    heights = [1,1]
    print(maxArea(heights))