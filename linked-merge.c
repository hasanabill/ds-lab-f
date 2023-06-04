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
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
    }
}

struct Node *mergeLinkedLists(struct Node *first, struct Node *second)
{
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;

    struct Node *mergedList = NULL;

    if (first->data <= second->data)
    {
        mergedList = first;
        mergedList->next = mergeLinkedLists(first->next, second);
    }
    else
    {
        mergedList = second;
        mergedList->next = mergeLinkedLists(first, second->next);
    }

    return mergedList;
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
    struct Node *first = NULL;
    struct Node *second = NULL;

    insert(&first, 1);
    insert(&first, 3);
    insert(&first, 5);

    insert(&second, 2);
    insert(&second, 4);
    insert(&second, 6);

    printf("First Linked List:\n");
    printLinkedList(first);

    printf("Second Linked List:\n");
    printLinkedList(second);

    struct Node *mergedList = mergeLinkedLists(first, second);

    printf("Merged Linked List:\n");
    printLinkedList(mergedList);

    return 0;
}
