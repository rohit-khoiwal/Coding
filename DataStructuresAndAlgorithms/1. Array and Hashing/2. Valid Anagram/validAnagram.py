from collections import Counter

def isAnagram(s: str, t: str) -> bool:
    if len(s) != len(t):
        return False
    counts = Counter(s)
    for i in t:
        if i in counts:
            if counts[i] <= 0:
                return False
            counts[i] -= 1
        else: return False
    return True

if __name__ == '__main__':
    #s = "rat" t = "car"
    s = "anagram" 
    t = "nagaram"
    print(isAnagram(s, t))
        