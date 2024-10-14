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
    if (p == nullptr)
    {
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
    if (prevNode == nullptr)
    {
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
Node *InsertInBetween(Node *head, int pos, int data)
{
    if (pos <= 0)
    {
        cout << "Position should be greater than 0";
        return head;
    }
    Node *ptr = new Node(data);
    Node *p = head;
    int count = 1; // start from 1 for easier positioning
    if (pos == 1)
    {
        head = InsertAtFirst(head, data);
        return head;
    }
    while (count != pos - 1 && p != nullptr)
    {
        p = p->next;
        count++;
    }
    if (p == nullptr)
    {
        cout << "Position is beyond the length of the list or list doesnt exists \n";
        return head;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

void LinkedListTraverse(Node *head)
{
    if (head == nullptr)
    {
        cout << "you dog" << endl;
        return;
    }
    Node *start = head;
    while (start->next != nullptr)
    {
        cout << "element : " << start->data << endl;
        start = start->next;
    }
}

int main()
{
    Node *head = nullptr; // Initialize head pointer
    head = InsertAtFirst(head, 80);
    int a;

    cout << endl;
    char continueloop = 'y';
    while (continueloop == 'y')
    {
        cout << "the available operations are 1:insert  2:delete 3:display : ";
        cin >> a;
        switch (a)
        {
        case 1:
            int pos, data;
            cout << "enter the position of data entry : ";
            cin >> pos;
            cout << "enter data : ";
            cin >> data;
            InsertInBetween(head, pos, data);
            break;
        case 2:
            cout << "not available right now" << endl;
            break;
        case 3:
            LinkedListTraverse(head);
            break;
        }
        cout << "wanna continue y/n  : ";
        cin >> continueloop;
        cout << endl;
    }
    return 0;
}
