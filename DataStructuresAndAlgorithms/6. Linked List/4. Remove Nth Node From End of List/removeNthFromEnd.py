class ListNode:
    def __init__(self, val, next=None):
        self.val = val
        self.next = next
    
def printlinkedlist(head):
    if head == None:
        return
    while head != None:
        print(head.val, end=' ')
        head = head.next

def create(lst):
    head = ListNode(lst[0])
    l = head
    for i in lst[1:]:
        l.next = ListNode(i)
        l = l.next
    return head

def removeNthFromEnd(head, n: int):
    prevNodes = [None]
    stack = []
    nextNodes = []
    tmp = head
    l = 0
    while tmp != None:
        l += 1
        prevNodes.append(tmp)
        stack.append(tmp)
        nextNodes.append(tmp.next)
        tmp = tmp.next
    n = l - n
    prevNode = prevNodes[n]
    nextNode = nextNodes[n]
    if prevNode == None:
        return nextNode
    prevNode.next = nextNode
    return head    
    
if __name__ == '__main__':
    head = [1, 2]
    head = create(head)
    printlinkedlist(head)
    print()
    n = 2
    head = removeNthFromEnd(head, n)
    printlinkedlist(head)