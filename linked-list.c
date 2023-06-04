#include <stdio.h>
#include <stdlib.h>

void menu();
void create_list();
void display();
void insert_mid();
void del_mid();
void split();
void merge();

struct node
{
    int data;
    struct node *next;
};
struct node *head, *head1, *head2, *new_node, *new_node1, *temp;
int count = 0;

int main()
{
    menu();

    return 0;
}

void menu()
{
    printf("1. Create a Linked List\n2. Display the list\n3. Insert a node after a postion\n4. Delete a node after a position\n5. Split the list\n6. Merge two list\n\nPlease enter your choice: ");
    int choice;
lbl1:
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        create_list();
        break;
    case 2:
        display();
        break;
    case 3:
        insert_mid();
        break;
    case 4:
        del_mid();
        break;
    case 5:
        split();
        break;
    case 6:
        merge();
        break;
    default:
        printf("\nINVALID INPUT. Please enter a valid input: ");
        goto lbl1;
    }
}

void create_list()
{
    int choice;
    head = 0;
    while (choice)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &new_node->data);

        if (head == 0)
        {
            head = temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
        }
        printf("Continue or not (0,1): ");
        scanf("%d", &choice);
        count++;
    }
    menu();
}

void display()
{
    temp = head;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    menu();
}

void insert_mid()
{
    int pos, i = 1;

    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos > count)
    {
        printf("Invalid!!");
    }
    else
    {
        temp = head;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        new_node = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value you want to enter: ");
        scanf("%d", &new_node->data);
        new_node->next = temp->next;
        temp->next = new_node;
    }
    menu();
}

void del_mid()
{
    struct node *next_node;
    int pos, i = 1;
    temp = head;

    printf("Enter the position: ");
    scanf("%d", &pos);

    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    next_node = temp->next;
    temp->next = next_node->next;
    free(next_node);

    menu();
}

void split()
{
    int p, i = 1;

    printf("Enter the position you want to split from: ");
    scanf("%d", &p);

    head1 = head;
    head2 = NULL;
    temp = head;

    while (i != p)
    {
        i++;
        temp = temp->next;
    }
    head2 = temp->next;
    temp->next = NULL;

    temp = head2;
    while (temp != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    display();

    menu();
}

void merge()
{

    head = head1;
    temp = head1;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head2;
    display();
    menu();
}
