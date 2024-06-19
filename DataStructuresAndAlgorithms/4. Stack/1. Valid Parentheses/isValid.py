def isValid(s: str) -> bool:
    checkPair = {'{' : '}', '(': ')', '[': ']'}
    stack = []
    for c in s:
        if c == "(" or c == "[" or c == "{":
            stack.append(c)
        else:
            if len(stack) == 0 or c != checkPair[stack.pop()]:
                return False
    return len(stack) == 0

if __name__ == '__main__':
    s = "()[]{}"
    print(isValid(s))