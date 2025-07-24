#include <stdio.h> // Include the standard input/output header file
#include <stdlib.h> 
#include <math.h> // Include the math header file for mathematical functions
#include <ctype.h> // Include the character type header file for checking character types

// Define a global variable 'top' to keep track of the top element in the stack
int top = -1;

// Define a global stack array 's' to store operands and operators
float s[50];

// Function to perform arithmetic operations based on the given operator symbol
float operate(float opr1, float opr2, char symbol) 
{
    switch (symbol) 
    {
        case '+':
            return (opr1 + opr2);
        case '-':
            return (opr1 - opr2);
        case '*':
            return (opr1 * opr2);
        case '/':
            return (opr1 / opr2);
        case '^':
            return (pow(opr1, opr2));
        default:
            printf("\nInvalid operator: %c\n", symbol);
            exit(1); // Terminate the program if an invalid operator is encountered
    }
}

// Function to push a value onto the stack
void push(float symbol) 
{
    s[++top] = symbol; // Increment the top pointer and store the value in the stack
}

// Function to pop a value from the stack
float pop() 
{
    return s[top--]; // Decrement the top pointer and return the popped value
}

// Function to evaluate the postfix expression
float eval(char postfix[50]) 
{
    int i;
    char symbol;
    float opr1, opr2, value, res;

    // Iterate through the postfix expression
    for (i = 0; postfix[i] != '\0'; i++) 
    {
        symbol = postfix[i];

        // Check if the current character is a digit
        if (isdigit(symbol)) 
        {
            // Convert the digit character to its corresponding numeric value and push it onto the stack
            push(symbol - 48);
        }

        // Check if the current character is an alphabet representing a variable
        else if (isalpha(symbol)) 
        {
            printf("\n Enter the value for %c ", symbol); // Prompt the user to enter the value of the variable
            scanf("%f", &value); // Scan the input value
            push(value); // Push the input value onto the stack
        }

        // Otherwise, it's an operator
        else 
        {
            // Pop two operands from the stack
            opr2 = pop();
            opr1 = pop();

            // Perform the operation based on the operator symbol
            res = operate(opr1, opr2, symbol);

            // Push the result of the operation onto the stack
            push(res);
        }
    }

    // Return the top element of the stack, which is the final result of the evaluation
    return pop();
}

int main() 
{
    char postfix[80];
    float res;

    // Prompt the user to enter the postfix expression
    printf("\n Enter The Postfix Expression \n");
    gets(postfix); // Read the input expression

    // Display the given expression
    printf("The Given Expression is :");
    puts(postfix);

    // Evaluate the postfix expression and store the result in 'res'
    res = eval(postfix);

    // Display the final result of the evaluation
    printf("\nThe value of the expression is %f\n", res);

    return 0;
}
