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

def mergeTwoLists(list1, list2):
    if list1 == None or list2 == None:
        return
    
    if list1.val < list2.val:
        head = list1
        list1 = list1.next
    else:
        head = list2
        list2 = list2.next
    prevNode = head
    while True:
        if list1 == None:
            prevNode.next = list2
            break
        elif list2 == None:
            prevNode.next = list1
            break
        if list1.val > list2.val:
            prevNode.next = list2
            prevNode = list2
            list2 = prevNode.next
        else:
            prevNode.next = list1
            prevNode = list1
            list1 = prevNode.next

    return head

if __name__ == '__main__':
    list1 = [1,2,4]
    head1 = create(list1)
    list2 = [1,3,4]
    head2 = create(list2)

    head = mergeTwoLists(head1, head2)
    printlinkedlist(head)
    