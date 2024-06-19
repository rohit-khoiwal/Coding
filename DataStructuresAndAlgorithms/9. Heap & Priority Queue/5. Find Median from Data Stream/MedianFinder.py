import heapq

class MedianFinder:

    def __init__(self):
        self.nums = []
        self.size = 0
        self.left = None
        self.right = None
    def addNum(self, num: int) -> None:
        heapq.heappush(self.nums, num)
        self.size += 1
        print(self.nums)
        # if self.size == 1:
        #     self.left = self.nums[0]
        #     self.right = self.nums[0]
        #     return 
        # # print(self.size%2)
        # if self.size%2 == 0:
        #     self.right = 
        # else:
        #     self.left = 
    def findMedian(self) -> float:
        pass

if __name__ == '__main__':
    obj = MedianFinder()
    methods = ["addNum", "addNum", "findMedian", "addNum", "findMedian"]
    arguments = [[1], [2], [], [3], []] 
    methods = ["addNum", "addNum", "addNum", "addNum", "addNum", "addNum", "addNum"]
    arguments = [[11], [30], [31], [92], [55], [56], [25]] 
    for i, method in enumerate(methods):
        if method == "addNum":
            print(obj.addNum(arguments[i][0]), end=' ')
        else:
            print(obj.findMedian(), end=' ')
        