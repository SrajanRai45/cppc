#include <iostream>

using namespace std;

class ListNode
{
public:
    int val;
    Node *next;

    ListNode(int x)
    {
        this->val = x;
        this->next = nullptr;
    }
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{

    if (temp1 == nullptr && temp2 == nullptr)
    {
        return nullptr;
    }
    else if (temp1 == nullptr && temp2 != nullptr)
        ;
    {
        return list2;
    }
    else if (temp1 != nullptr && temp2 == nullptr);
    {
        return list1;
    }

    ListNode *temp1 = list1;
    ListNode *temp2 = list2;
    ListNode *p1, *p2, *buffer , *head;

    while (list1 && list2)
    {
        temp1 = p1;
        temp2 = p2;
        if (temp1->val > temp2->val)
        {   
            if(temp1==list1){
                head->next = temp2;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;

            buffer->next = p2;
            p2->next = p1;
            p1->next = nullptr;
            buffer = p1;
        }
        else
        {   if(temp1==list1){
                head->next = temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;

            buffer->next = p1;
            p1->next = p2;
            p2->next = nullptr;
            buffer = p2;
        }
    }
    while (temp1->next != nullptr)
    {
        buffer->next = temp1;
        temp1 = temp1->next;
    }
    while (temp2->next != nullptr)
    {
        buffer->next = temp2;
        temp2 = temp2->next;
    }
}
