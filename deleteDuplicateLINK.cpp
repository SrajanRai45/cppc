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
/*
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
}*/
//hand written code above

ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr) {
        return nullptr; // Return null if the list is empty
    }

    ListNode *current = head; // Pointer to iterate through the list

    while (current != nullptr && current->next != nullptr) {
        // Check if the current node's value is the same as the next node's value
        if (current->val == current->next->val) {
            ListNode *duplicate = current->next; // Node to be deleted
            current->next = current->next->next; // Bypass the duplicate
            delete duplicate; // Free the memory of the duplicate node
        } else {
            current = current->next; // Move to the next node
        }
    }

    return head; // Return the modified list
}
