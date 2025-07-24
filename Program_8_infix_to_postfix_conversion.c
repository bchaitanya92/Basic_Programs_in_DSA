#define SIZE 50 /* Define a constant 'SIZE' for the stack size */
#include <ctype.h> /* Include the header file for character type checking */
#include <stdio.h> /* Include the standard input/output header file */

// Declare a global character stack 's' with a size of 'SIZE'
char s[SIZE];

// Initialize a global variable 'top' to track the top element in the stack
int top = -1;

// Function to push a character element onto the stack
void push(char elem) 
{
    // Increment the top pointer and store the element in the stack
    s[++top] = elem;
}

// Function to pop a character element from the stack
char pop() 
{
    // Return the element at the top of the stack and decrement the top pointer
    return (s[top--]);
}

// Function to determine the precedence of an operator
int pr(char elem) 
{
    switch (elem) 
    {
        case '#': // Special case for the dummy symbol '#'
            return 0;
        case '(': // Lowest precedence for '('
            return 1;
        case '+': // Precedence for '+' and '-'
        case '-':
            return 2;
        case '*': // Precedence for '*' and '/'
        case '/':
        case '%':
            return 3;
        case '^': // Highest precedence for '^'
            return 4;
        default:
            printf("\nInvalid operator: %c\n", elem); // Handle invalid operators
            exit(1); // Terminate the program if an invalid operator is encountered
    }
}

void main() 
{
    // Declare character arrays for infix and postfix expressions
    char infx[50], pofx[50];
    char ch, elem; // Declare variables for characters and stack elements

    // Prompt the user to enter the infix expression
    printf("\n Read the Infix Expression: ");
    scanf("%s", infx); // Read the input infix expression

    // Push a dummy symbol '#' onto the stack
    push('#');

    // Initialize indices for infix and postfix expressions
    int i = 0, k = 0;

    // Process the infix expression
    while ((ch = infx[i++]) != '\0') 
    {
        // Check if the current character is an operand
        if (isalnum(ch)) 
        {
            // Append the operand to the postfix expression
            pofx[k++] = ch;
        }

        // Check if the current character is an opening parenthesis '('
        else if (ch == '(') 
        {
            // Push '(' onto the stack
            push(ch);
        }

        // Check if the current character is a closing parenthesis ')'
        else if (ch == ')') 
        {
            // Pop characters from the stack until '(' is encountered
            while (s[top] != '(') 
            {
                pofx[k++] = pop(); // Append popped operators to postfix expression
            }

            // Remove the '(' from the stack
            elem = pop(); // Pop '('
        }

        // Otherwise, it's an operator
        else 
        {
            // Pop operators from the stack until their precedence is less than the current operator
            while (pr(s[top]) >= pr(ch)) 
            {
                pofx[k++] = pop(); // Append popped operators to postfix expression
            }

            // Push the current operator onto the stack
            push(ch);
        }
    }

    // Pop remaining operators from the stack
    while (s[top] != '#') 
    {
        pofx[k++] = pop(); // Append popped operators to postfix expression
    }

    // Terminate the postfix expression with a null character
    pofx[k] = '\0';

    // Display the given infix and postfix expressions
    printf("\n Given Infix Expression: %s \n Postfix Expression: %s \n", infx, pofx);
}
