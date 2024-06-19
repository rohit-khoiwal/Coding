import re
def isPalindrome(s: str) -> bool:
    s = s.lower()
    s = re.sub(r'[\W_]+', '', s)
    
    for i in range(len(s)//2):
        if s[i] == s[len(s) - i - 1]:continue
        return False
    return True

if __name__ == '__main__':
    s = "A man, a plan, a canal: Panama"
    # s = "race a car"
    # s = " "
    print(isPalindrome(s))