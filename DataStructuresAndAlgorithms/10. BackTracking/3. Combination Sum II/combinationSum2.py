def combinationSum(candidates, target: int):
    res = []
    # candidates.sort()
    def dfs(i, total, currSet):
        if total == target:
            # print(currSet)
            res.append(currSet.copy())
            
        prev = -1
        for i in range(i, len(candidates)):
            if candidates[i] == prev:
                    continue
            if total + candidates[i] <= target:
                currSet.append(candidates[i])
                dfs(i + 1, total + candidates[i], currSet)
                _ = currSet.pop()
            prev = candidates[i]
    
    dfs(0, 0, [])
    return res


if __name__ == '__main__':
    candidates = [10,1,2,7,6,1,5]
    target = 8
    # candidates = [2,5,2,1,2]
    # target = 5
    print(combinationSum(candidates, target))