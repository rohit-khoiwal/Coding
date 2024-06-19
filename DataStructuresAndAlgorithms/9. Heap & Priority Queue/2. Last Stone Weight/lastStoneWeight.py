import heapq

def lastStoneWeight(stones):
    stones = [-stone for stone in stones]
    heapq.heapify(stones)
    while stones:
        if len(stones) == 1:
            return -stones[0]
        firstMax = -heapq.heappop(stones)
        secondMax = -heapq.heappop(stones)
        if firstMax == secondMax:
            continue
        else:
            heapq.heappush(stones, -(firstMax-secondMax))
    return 0


if __name__ == "__main__":
    stones = [2,7,4,1,8,1]
    print(lastStoneWeight(stones))