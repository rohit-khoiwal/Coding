import heapq
def kClosest(points, k: int):
    distMetric = []
    fn = lambda x : x[0]**2 + x[1]**2
    for point in points:
        distance = fn(point)
        distMetric.append([distance, point])
    
    heapq.heapify(distMetric)
    return [heapq.heappop(distMetric)[1] for _ in range(k)]

if __name__ == '__main__':
    points = [[1,3],[-2,2]]
    k = 1
    points = [[3,3],[5,-1],[-2,4]]
    k = 2
    print(kClosest(points, k))