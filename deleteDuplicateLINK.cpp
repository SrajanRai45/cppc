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

ListNode *deleteDuplicates(ListNode *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    ListNode *prev = head;

    while (prev->next != nullptr && prev->next->next != nullptr)
    {
        if (prev->val == prev->next->val)
        {
            prev->next = prev->next->next;
            ListNode *buff = prev->next;
            delete buff;
        }
        else
        {
            prev = prev->next;
        }
    }
    return head;
}