#include <stdio.h>
#include <stdlib.h>

void menu();

int ar[100];
int n, front = 0, rear = -1, count = 0, value;

int full()
{
    if (count == n)
        return 1;
    else
        return 0;
}

int empty()
{
    if (count == 0)
        return 1;
    else
        return 0;
}

void enqueue()
{
    if (full())
    {
        printf("Queue is full\n");
    }
    else
    {
        if (rear == (n - 1))
        {
            rear = 0;
            printf("Enter the element: ");
            scanf("%d", &value);
            ar[rear] = value;
            count++;
            printf("Enqueued. \n");
        }
        else
        {
            printf("Enter the element: ");
            scanf("%d", &value);
            rear++;
            ar[rear] = value;
            count++;
            printf("Enqueued. \n");
        }
    }
    menu();
}

void dequeue()
{
    if (empty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        ar[front] = NULL;
        count--;
        printf("Dequeued\n");
        if (front == (n - 1))
            front = 0;
        else
            front++;
    }
    menu();
}

void print()
{
    for (int i = 0; i < n; i++)
    {
        if (ar[i] == NULL)
            printf("__ ");
        else
            printf("%d ", ar[i]);
    }
    printf("\n");
    menu();
}

void menu()
{

    int choice;
    while (1)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            print();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
}

int main()
{
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    menu();

    return 0;
}