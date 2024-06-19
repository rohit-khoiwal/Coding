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