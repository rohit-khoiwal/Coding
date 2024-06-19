import heapq
class KthLargest:
    def __init__(self, k: int, nums: list):
        self.k = k
        self.heap = nums
        heapq.heapify(self.heap)
        
        while len(self.heap) > k:
            heapq.heappop(self.heap)

    def add(self, val: int) -> int:
        heapq.heappush(self.heap, val[0])
        if len(self.heap) > self.k:
            heapq.heappop(self.heap)
        return self.heap[0]
        


if __name__ == '__main__':
    obj = KthLargest(3, [4, 5, 8, 2])
    methods = ["add", "add", "add", "add", "add"]
    arguments = [[3], [5], [10], [9], [4]]
    for i, method in enumerate(methods):
        if method == 'add':
            print(obj.add(arguments[i]),end=' ')