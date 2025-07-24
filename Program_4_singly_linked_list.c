#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stud {
    char usn[15], name[25], branch[30], phone[20];
    int sem;
    struct stud *next;
} node;

node *start = NULL;

void display();
void insert_front();
void createSLL();
void insert_end();
void del_front();
void del_end();

node* getnode() 
{
    node *new1;
    new1 = (node *)malloc(sizeof(node));
    printf("Enter the student \nUsn \nName \nBranch \nSemester \nPhone Number\n");

    if (scanf("%s %s %s %d %s", new1->usn, new1->name, new1->branch, &new1->sem, new1->phone) != 5) 
    {
        printf("Invalid input format. Exiting...\n");
        exit(1);
    }

    new1->next = NULL;
    while ((getchar()) != '\n');  // Clear input buffer
    return new1;
}

// Function to display the linked list
void display() 
{
   node *temp = start;  // Temporary pointer to traverse the list
   int count = 0;       // Counter for the number of nodes
    if (start == NULL) 
    {
        printf("List Empty\n");
        return;
    }
    printf("\nUSN\tName\tBranch\t\tSemester\t\tPhone Number\n");
    while (temp != NULL) 
    {
        printf("%s\t%s\t%s\t\t%d\t\t%s\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phone);
        temp = temp->next;
        count++;
    }
    printf("The number of nodes are: %d\n ", count);
}

// Function to insert a new node at the front of the linked list
void insert_front() 
{
    node *new1;
    new1 = getnode();       // Create a new node
    if (start == NULL) 
    {
        start = new1;
        return;
    }
    new1->next = start;      // Link the new node to the current head
    start = new1;            // Update the head pointer
}

// Function to create a singly linked list by inserting nodes at the front
void createSLL() 
{
    int n, i = 0;
    printf("Enter the number of students to be created\n");
    scanf("%d", &n);
    while (i < n) 
    {
        i++;
        insert_front(); // or call insert_end();  // Insert nodes at the front (you can also use insert_end())
    }
    return;
}

// Function to insert a new node at the end of the linked list
void insert_end() 
{
    node *new1, *temp = start;
    new1 = getnode();
    if (start == NULL) 
    {
        start = new1;
        return;
    }
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = new1;
}

// Function to delete a node from the front of the linked list
void del_front() 
{
    node *temp;
    if (start == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    temp = start;
    start = start->next;
    printf("The node of student usn %s is deleted\n", temp->usn);
    free(temp);
}

// Function to delete a node from the end of the linked list
void del_end() 
{
    node *cur, *pre = NULL;
    if (start == NULL) 
    {
        printf("List is empty\n");
        return;
    }
    cur = start;
    while (cur->next != NULL) 
    {
        pre = cur;
        cur = cur->next;
    }
    if (pre == NULL)
        start = NULL;
    else
        pre->next = NULL;
    printf("The node of student usn %s is deleted\n", cur->usn);
    free(cur);
}

// Main function
int main() 
{
    int ch;
    for (;;) 
    {
        printf("\n 1: Create SLL \n 2: Insert Front \n 3: Insert End \n 4: Delete Front \n 5: Delete End \n 6: Display\n 7: Exit \n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);
        switch (ch) 
        {
            case 1:
                createSLL();
                break;
            case 2:
                insert_front();
                break;
            case 3:
                insert_end();
                break;
            case 4:
                del_front();
                break;
            case 5:
                del_end();
                break;
            case 6:
                display();
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    }
    return 0;
}
