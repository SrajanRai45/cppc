#include <stdio.h>
#include <stdlib.h>

struct link {
    int coef, expo;
    struct link *next;
} *head1, *tail1, *head2, *tail2;

typedef struct link Node;

Node* create(void);
void display(Node *);
Node* add(void);

int main() {
    Node *head3;
    head1 = tail1 = NULL;
    head2 = tail2 = NULL;

    printf("Create the first polynomial:\n");
    head1 = create();
    printf("Create the second polynomial:\n");
    head2 = create();

    head3 = add();

    printf("\nFirst polynomial is:\n");
    display(head1);
    printf("\nSecond polynomial is:\n");
    display(head2);
    printf("\nResultant polynomial after addition is:\n");
    display(head3);

    return 0;
}

Node *create(void) {
    Node *head = NULL, *tail = NULL;
    char ch = 'y';

    printf("Enter the terms of the polynomial (coefficient and exponent):\n");
    while (ch == 'y') {
        Node *newNode = (Node *)malloc(sizeof(Node));

        printf("Coefficient: ");
        scanf("%d", &newNode->coef);
        printf("Exponent: ");
        scanf("%d", &newNode->expo);

        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        printf("Do you want to add another term? (y/n): ");
        getchar();  // To consume the newline character
        scanf("%c", &ch);
    }
    
    return head;
}

Node* add(void) {
    Node *h1 = head1, *h2 = head2, *h3 = NULL, *t3 = NULL;

    while (h1 != NULL && h2 != NULL) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->next = NULL;

        if (h1->expo > h2->expo) {
            newNode->coef = h1->coef;
            newNode->expo = h1->expo;
            h1 = h1->next;
        } else if (h2->expo > h1->expo) {
            newNode->coef = h2->coef;
            newNode->expo = h2->expo;
            h2 = h2->next;
        } else {  // Exponents are equal
            newNode->coef = h1->coef + h2->coef;
            newNode->expo = h1->expo;
            h1 = h1->next;
            h2 = h2->next;
        }

        if (h3 == NULL) {
            h3 = t3 = newNode;
        } else {
            t3->next = newNode;
            t3 = newNode;
        }
    }

    // If one list still has remaining terms
    while (h1 != NULL) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->coef = h1->coef;
        newNode->expo = h1->expo;
        newNode->next = NULL;

        if (h3 == NULL) {
            h3 = t3 = newNode;
        } else {
            t3->next = newNode;
            t3 = newNode;
        }

        h1 = h1->next;
    }

    while (h2 != NULL) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->coef = h2->coef;
        newNode->expo = h2->expo;
        newNode->next = NULL;

        if (h3 == NULL) {
            h3 = t3 = newNode;
        } else {
            t3->next = newNode;
            t3 = newNode;
        }

        h2 = h2->next;
    }

    return h3;
}

void display(Node *start) {
    if (start == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }

    while (start != NULL) {
        printf("%dx^%d", start->coef, start->expo);
        if (start->next != NULL) {
            printf(" + ");
        }
        start = start->next;
    }
    printf("\n");
}
