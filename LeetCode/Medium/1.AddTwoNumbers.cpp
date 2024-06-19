#include <iostream>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* head = NULL;
        ListNode* prevNode = NULL;
        ListNode* newNode = NULL;
        int carry = 0;
        int nodeSumVal = 0;
        while(true)
        {
            if(!l1 && !l2)
                break;

            newNode = new ListNode();
            if(!l2)
            {
                nodeSumVal = l1->val + carry;
                l1 = l1->next;
            }
            else if(!l1)
            {
                nodeSumVal = l2->val + carry;
                l2 = l2->next;
            }
            else
            {
                nodeSumVal = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }

            carry = 0;
            if(nodeSumVal > 9)
                carry = 1;
                
            newNode->val = nodeSumVal%10;
            if(!head)
                head = newNode;
            if(!prevNode)
                prevNode = newNode;
            else
            {
                prevNode->next = newNode;
                prevNode = newNode;
            }
        }

        if(carry != 0)
        {
            newNode = new ListNode();
            newNode->val = carry;
            prevNode->next = newNode;
        }
        return head;
    }
};  

int main()
{
    int arr1[7] = {9,9,9,9,9,9,9};
    int arr2[4] = {9,9,9,9};
    ListNode* l1 =NULL;
    ListNode* l2 = NULL;
    ListNode* newNode = NULL;
    ListNode* prevNode = NULL;
    for(int i = 0; i < 7; i++)
    {
        newNode = new ListNode();
        newNode->val = arr1[i];
        if(!l1)
        {
            l1 = newNode;
            prevNode = newNode;
        }
        else
        {
            prevNode->next = newNode;
            prevNode = newNode;
        }
    }
    for(int i = 0; i < 4; i++)
    {
        newNode = new ListNode();
        newNode->val = arr1[i];
        if(!l2)
        {
            l2 = newNode;
            prevNode = newNode;
        }
        else
        {
            prevNode->next = newNode;
            prevNode = newNode;
        }
    }

    Solution s;
    cout<<s.addTwoNumbers(l1, l2);
}