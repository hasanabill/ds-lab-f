#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insert(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void deleteNode(struct Node **head, int value)
{
    if (*head == NULL)
        return;

    struct Node *current = *head;
    struct Node *previous = NULL;

    if (current != NULL && current->data == value)
    {
        *head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->data != value)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
        return;

    previous->next = current->next;
    free(current);
}

void printLinkedList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;

    insert(&head, 6);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 8);
    insert(&head, 3);

    printf("Original Linked List:\n");
    printLinkedList(head);

    deleteNode(&head, 2);

    printf("Linked List after Deletion:\n");
    printLinkedList(head);

    deleteNode(&head, 6);

    printf("Linked List after Deletion:\n");
    printLinkedList(head);

    return 0;
}
