#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 3

struct node
{
    int data;
    struct node *next;
};

struct node *head[TABLE_SIZE] = {NULL};

/* Insert a value into the hash table */
void insert(int val)
{
    int i = val % TABLE_SIZE;

    struct node *newnode =
        (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    newnode->data = val;
    newnode->next = NULL;

    if (head[i] == NULL)
    {
        head[i] = newnode;
    }
    else
    {
        struct node *c = head[i];

        while (c->next != NULL)
        {
            c = c->next;
        }

        c->next = newnode;
    }
}

/* Display the hash table */
void display()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("Entries at index %d: ", i);

        struct node *temp = head[i];

        if (temp == NULL)
        {
            printf("No Hash Entry\n");
        }
        else
        {
            while (temp != NULL)
            {
                printf("%d -> ", temp->data);
                temp = temp->next;
            }

            printf("NULL\n");
        }
    }
}

int main()
{
    int opt, val;

    while (1)
    {
        printf("\nPress 1. Insert\t2. Display\t3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);

        switch (opt)
        {
            case 1:
                printf("\nEnter a value to insert into hash table: ");
                scanf("%d", &val);

                insert(val);
                printf("Value inserted successfully.\n");
                break;

            case 2:
                printf("\nHash Table:\n");
                display();
                break;

            case 3:
                printf("\nExiting program...\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}