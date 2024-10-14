#include <iostream>
// Given a linked list, the task is to reverse the linked list by changing the links between nodes.
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


//somethins wrong with it or memory
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

void printList(Node *node)
{
    while (node != nullptr)
    {
        cout << " " << node->data;
        node = node->next;
    }
}

/*Node *ReverseLinked(Node *head)
{
    Node *start;
    Node *pstart;

    int len = LinkedListLen(head);

    // previous try
    while (head->next != nullptr)
    {
        start = head;
        pstart = head;
        for (int i = 0; i < len; i++)
        {
            if (i == len - 1)
            {
                start = start->next;
            }
            pstart = pstart->next;
        }
        pstart->next = start;
        len = len - 1;

        if (len == 0)
        {
            head->next = nullptr;
        }
    }
    return head;
}*/

// geeks soluton
Node *reverseList(Node *head)
{

    // Initialize three pointers: curr, prev and next
    Node *curr = head, *prev = nullptr, *next;
    //prev = null because it wants head pointer to be null and reverse lists head as tail of preveious 
    // Traverse all the nodes of Linked List
    while (curr != nullptr)
    {

        // Store next
        next = curr->next;

        // Reverse current node's next pointer
        curr->next = prev;

        // Move pointers one position ahead
        prev = curr;
        curr = next;
    }

    // Return the head of reversed linked list
    return prev;
}

int main()
{
    Node *tail;
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    tail = head->next->next->next->next;
    // LinkedListTraverse(head);
    head = reverseList(head);
    printList(head);
    return 0;
}