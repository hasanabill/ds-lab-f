#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertFirst(struct Node **head, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}

void insertMiddle(struct Node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("The previous node cannot be NULL");
        return;
    }
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void insertLast(struct Node **head, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    return;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main()
{
    struct Node *head = NULL;
    int choice, data, position;

    while (1)
    {
        printf("\nChoose an option:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the middle\n");
        printf("3. Insert at the end\n");
        printf("4. Print Linked list\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            insertFirst(&head, data);
            printf("List after insertion: ");
            printList(head);
            break;

        case 2:
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            insertMiddle(head, data);
            printf("List after insertion: ");
            printList(head);
            break;

        case 3:
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            insertLast(&head, data);
            printf("List after insertion: ");
            printList(head);
            break;

        case 4:
            printf("List: ");
            printList(head);
            break;

        case 5:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}