#include <iostream>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int x)
    {
        this->val = x;
        this->next = nullptr;
    }
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *head = new ListNode(0);
    ListNode *temp1 = list1;
    ListNode *temp2 = list2;
    ListNode *buffer = head;

    if (temp1 == nullptr)
    {
        return temp2;
    }
    if (temp2 == nullptr)
    {
        return temp1;
    }

    while(temp1 != nullptr && temp2 != nullptr){
        if(temp1->val > temp2->val){
            buffer->next = temp2;
            temp2 = temp2->next;

        }else{
            buffer->next = temp1;
            temp1 = temp1->next;
        }
    }
    if(temp1 !=nullptr){
        buffer->next = temp1;
    }
    if(temp2 !=nullptr){
        buffer->next = temp2;
    }
    return head->next;
}