#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

int stack[MAX], top = -1;
char stack1[MAX], top1 = -1;

// Function to push an element onto the integer stack
void push()
{
    int ele;
    if (top < MAX - 1)
    {
        printf("Enter the value to be inserted into the stack: \n");
        scanf("%d", &ele);
        stack[++top] = ele;
    }
    else
        printf("\n Stack is full. \n");
    return;
}
/*
void push() {
    if (top < MAX - 1) {
        printf("Enter the value to be inserted into the stack: \n");
        scanf("%d", &stack[++top]);
    } else {
        printf("\n Stack is full. \n");
    }
}
*/

// Function to pop an element from the character stack
void pop()
{
    if (top1 != -1)
    {
        printf("\n The element deleted from the stack is: %c \n", stack1[top1--]);
    }
    else
        printf("\n Stack is empty. \n");
    return;
}

// Function to check if a string is a palindrome
void palindrome()
{
    int i, count = 0, len;
    char str[100];
    printf("\n Entering to check whether it is palindrome or not: ");
    scanf("%s", str);
    len = strlen(str);
    top1 = -1;

    // Push each character of the string onto the character stack
    for (i = 0; i < len; i++)
    {
        stack1[++top1] = str[i];
    }

    // Pop each character and compare with the original string
    for (i = 0; i < len; i++)
    {
        if (str[i] == stack1[top1--])
            count++;
    }

    // If the count matches the length, it is a palindrome
    if (count == len)
        printf("\n %s is a palindrome string.\n", str);
    else
        printf("\n %s is not a palindrome string.\n", str);
    return;
}

// Function to check the status of the integer stack
void check()
{
    if (top >= MAX - 1)
        printf("\n Stack is overflow.\n");
    else if (top == -1)
        printf("\n Stack is underflow.\n");
    else
        printf("\n Stack operation can be performed.\n");
}

// Function to display the elements of the integer stack
void display()
{
    int i;
    if (top == -1)
    {
        printf("\n Stack is empty. \n");
    }
    else
    {
        printf("\n Elements in the stack are: \n");
        for (i = top; i >= 0; --i)
            printf(" %d \n", stack[i]);
    }
    return;
}

int main()
{
    int choice;
    while (1)
    {
        // Menu for stack operations
        printf("\n STACK OPERATIONS \n");
        printf("\n 1: Push \n 2: Pop \n 3: Palindrome \n 4: Check \n 5: Display \n 6: Exit \n");
        printf("\n Enter your choice [1/2/3/4/5/6]: ");
        scanf("%d", &choice);

        // Switch case for menu choices
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            palindrome();
            break;
        case 4:
            check();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}

