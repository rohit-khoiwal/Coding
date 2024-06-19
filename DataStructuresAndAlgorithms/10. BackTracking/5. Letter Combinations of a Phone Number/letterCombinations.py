def letterCombinations(digits):
    results = set()
    digitMap = {
        "2" : "abc", "3":"def", "4" : "ghi", "5" : "jkl", "6" : "mno", 
        "7" : "pqrs", "8" : "tuv", "9" : "wxyz"
    }
    def dfs(n, string):
        if n == len(digits):
            results.add(string)
            return
        for val in digitMap[digits[n]]:
            dfs(n+1, string+val)
    dfs(0, "")
    return list(results)

if __name__ == '__main__':
    digits = "23"
    print(letterCombinations(digits))