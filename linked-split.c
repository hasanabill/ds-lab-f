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

void splitLinkedList(struct Node *head, struct Node **firstHalf, struct Node **secondHalf)
{
    if (head == NULL || head->next == NULL)
    {
        *firstHalf = head;
        *secondHalf = NULL;
        return;
    }

    struct Node *slow = head;
    struct Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *firstHalf = head;
    *secondHalf = slow->next;
    slow->next = NULL;
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
    struct Node *firstHalf = NULL;
    struct Node *secondHalf = NULL;

    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);

    printf("Original Linked List:\n");
    printLinkedList(head);

    splitLinkedList(head, &firstHalf, &secondHalf);

    printf("First Half:\n");
    printLinkedList(firstHalf);

    printf("Second Half:\n");
    printLinkedList(secondHalf);

    return 0;
}
