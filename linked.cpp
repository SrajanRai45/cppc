#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        this->data = x;
        this->next = nullptr;
    }
};

// Insert at start
Node *InsertAtFirst(Node *head, int data)
{
    Node *ptr = new Node(data);
    ptr->next = head;
    return ptr;
}

// Insert at end
Node *InsertAtLast(Node *head, int data)
{
    Node *ptr = new Node(data);
    Node *p = head;
    if (p == nullptr) {
        return ptr;
    }
    while (p->next != nullptr) // Fixing the loop to stop at the last node
    {
        p = p->next;
    }
    p->next = ptr;
    return head;
}

// Insert after a given node
Node *InsertAfterNode(Node *head, Node *prevNode, int data)
{
    if (prevNode == nullptr) {
        cout << "The given previous node cannot be NULL";
        return head;
    }
    Node *ptr = new Node(data);
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

// Length of Linked List
int LinkedListLen(Node *head)
{
    Node *start = head;
    int len = 0;
    while (start != nullptr)
    {
        len++;
        start = start->next;
    }
    return len;
}

// Insert in between at a specific position
void InsertInBetween(Node *head, int pos, int data)
{
    if (pos <= 0) {
        cout << "Position should be greater than 0";
        return;
    }
    Node *ptr = new Node(data);
    Node *p = head;
    int count = 1; // start from 1 for easier positioning
    while (count != pos - 1 && p != nullptr)
    {
        p = p->next;
        count++;
    }
    if (p == nullptr) {
        cout << "Position is beyond the length of the list";
        return;
    }
    ptr->next = p->next;
    p->next = ptr;
}

int main()
{
    Node *head = nullptr; // Initialize head pointer
    head = InsertAtFirst(head, 10); // Example usage

    return 0;
}
