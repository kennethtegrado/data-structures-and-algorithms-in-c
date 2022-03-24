#include <stdio.h>
#include <stdlib.h>

// Implementation of Linked Lists
// Creating a node structure
typedef struct Node
{
    // Members of Node
    // Data, we can use any data type for this
    int data;

    // Use this as a pointer for the next node of a linked list
    struct Node *next;
} Node;

Node *first;

// Just a supplementary function to create a linkedlist
void Create(int *A, int size)
{
    // Traversing pointers
    Node *t, *last;

    // Declaration and initialization of first node
    first = (struct Node *)malloc(sizeof(Node));
    // Initialiaziation of its members
    first->data = A[0];
    first->next = NULL;

    // Set tail pointer to head
    last = first;

    // Creating the nodes of a linked list
    for (int iteration = 1; iteration < size; iteration++)
    {
        t = (struct Node *)malloc(sizeof(Node));
        t->data = A[iteration];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Use this function to display the contents of a linked lists
void Display(struct Node *p)
{
    // Traversing our linked lists
    while (p)
    {
        printf("%d \n", p->data);
        p = p->next;
    }
}

int main()
{
    int A[] = {3, 5, 7, 10, 15};

    Create(A, 5);

    Display(first);

    return 0;
}
