def lengthOfLongestSubstring(s: str) -> int:
    l = 0
    hashSet = set()
    maxLength = 0
    for i in range(len(s)):
        while s[i] in hashSet:
            hashSet.remove(s[l])
            l += 1
        hashSet.add(s[i])
        maxLength = max(maxLength, i - l + 1)
    return maxLength


if __name__ == '__main__':
    # s = "abcabcbb"
    # s = "bbbbb"
    s = "pwwkew"
    print(lengthOfLongestSubstring(s))