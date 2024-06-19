def permute(nums: list):
    res = []
    def dfs(currSet, visited):
        if not currSet:
            res.append(visited.copy())
            return
        for j in range(len(currSet)):
            visited.append(currSet[j])
            dfs(currSet[:j] + currSet[j + 1:], visited)
            visited.pop()

    dfs(nums, [])    
    return res


if __name__ == '__main__':
    nums = [1,2]
    print(permute(nums))