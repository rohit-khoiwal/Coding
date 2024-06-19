import heapq

def topKFrequent(nums: list, k: int) -> list:
    freqDict = {}
    for num in nums:
        freqDict[num] = freqDict.get(num, 0) + 1
    
    newlst = [(val, key) for (key, val) in freqDict.items()]
    heapq.heapify(newlst)
    return [i[1] for i in heapq.nlargest(k, newlst)]

if __name__ == '__main__':
    nums = [1,1,1,2,2,3]
    k = 2
    print(topKFrequent(nums, k))