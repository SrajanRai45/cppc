#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// insert at start
struct node *InsertAtFirst(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

// insert at end
struct node *InsertAtLast(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    while (p != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;

    return ptr;
}

// after insert func
struct node *InsertAfterNode(struct node *head, struct node *prevNode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

// length
int LinkedListLen(struct node *head)
{
    struct node *start = head;
    int len = 0;
    while (1)
    {
        len++;
        if (start->next == NULL)
        {
            break;
        }
        start = start->next;
    }
    return len;
}


// main insert function
void InsertInBetween(struct node *head, int pos, int data)
{

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int count = 0;
    while (count != pos - 1)
    {
        p = p->next;
        count++;
    }
    ptr->next = p->next;
    ptr->data = data;
    p->next = ptr;
}

int main()
{
    struct node *head;
    struct node *tail;
    struct node *start;

    return 0;
}
