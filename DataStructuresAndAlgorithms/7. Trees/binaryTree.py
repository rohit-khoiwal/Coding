class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def printTree(head):
    if head is None:
        return
    printTree(head.left)
    print(head.val)
    printTree(head.right)

def createTree(lst):
    head = TreeNode(lst[0])
    head.left = TreeNode(lst[1])
    head.right = TreeNode(lst[2])
    for i in range(1, len(lst)):
        head = TreeNode(lst[i])
        head.left = createTree(lst[i + 1:])
        head.right = createTree(lst[i + 1:])

if __name__ == "__main__":
    root = [4,2,7,1,3,6,9]
    