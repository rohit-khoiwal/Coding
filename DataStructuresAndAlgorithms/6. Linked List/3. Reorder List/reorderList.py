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

def reorderList(head) -> None:
    if head == None:
        return 
    end = head
    stack = []
    c = 0
    while end != None:
        c += 1
        stack.append(end)
        end = end.next
    for i in range((c-1)//2):
        node = stack.pop()
        tmp = head.next
        head.next = node
        head = tmp
        node.next = tmp
    node = stack.pop()
    node.next = None

if __name__ == '__main__':
    head = [1,2,3, 4]
    head = create(head)
    printlinkedlist(head)
    reorderList(head)
    print()
    printlinkedlist(head)
