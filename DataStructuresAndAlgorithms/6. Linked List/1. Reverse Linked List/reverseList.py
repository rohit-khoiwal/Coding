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

def reverseList(head):
    if head == None:
        return
    prevNode = None
    while head != None:
        tmp = head.next
        head.next = prevNode
        prevNode = head
        head = tmp
    return prevNode

if __name__ == '__main__':
    lst = [1,2,3,4,5]
    head = ListNode(lst[0])
    l = head
    for i in lst[1:]:
        l.next = ListNode(i)
        l = l.next

    printlinkedlist(head)
    print()
    head = reverseList(head)
    printlinkedlist(head)
    

