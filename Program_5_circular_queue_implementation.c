#include <stdio.h>
#include <stdlib.h>

#define size 5 // Define the size of the queue

int CQ[size]; // Array to store the queue elements
int f = -1; // Front pointer
int r = -1; // Rear pointer

// Check if the queue is full
int CQfull() 
{
    if ((f == r + 1) || (f == 0 && r == size - 1)) 
    {
        return 1; // Queue is full
    }
    return 0; // Queue is not full
}

// Check if the queue is empty
int CQempty() 
{
    if (f == -1) 
    {
        return 1; // Queue is empty
    }
    return 0; // Queue is not empty
}

// Insert an element into the queue
void CQinsert(int ele) 
{
    if (CQfull()) 
    {
        printf("\n Queue Overflow!!!\n"); // Handle overflow
    } 
    else 
    {
        if (f == -1) 
        { // If queue is empty
            f = 0; // Initialize front pointer
        }
        r = (r + 1) % size; // Update rear pointer
        CQ[r] = ele; // Add element to the queue
    }
}

// Delete an element from the queue
int CQdelete() 
{
    int ele; // Store the deleted element

    if (CQempty()) 
    {
        printf("\n Queue Underflow!!!\n"); // Handle underflow
        return -1; // Return error code
    } 
    else 
    {
        ele = CQ[f]; // Get the element to delete
        if (f == r) 
        { // If only one element is left
            f = -1; // Reset both pointers
            r = -1;
        } 
        else 
        {
            f = (f + 1) % size; // Update front pointer
        }
        return ele; // Return the deleted element
    }
}

// Display the contents of the queue
void display() 
{
    int i; // Loop counter

    if (CQempty()) 
    {
        printf("\n Queue is Empty.\n");
    } 
    else 
    {
        printf("front[%d]->", f); // Print the front element
        for (i = f; i != r; i = (i + 1) % size) 
        { // Loop through the queue
            printf(" %d ", CQ[i]); // Print each element
        }
        printf(" %d ", CQ[i]); // Print the last element
        printf("<-[%d]rear", r); // Print the rear element
    }
}

main() 
{
    // Main program to demonstrate circular queue operations
    int opn, ele;
    do 
    {
        printf("\n\n Circular QUEUE Operations\n");
        printf("\n 1. Insert");
        printf("\n 2. Delete");
        printf("\n 3. Display");
        printf("\n 4. Exit\n");
        printf("\n Your option:  ");
        scanf("%d", &opn);
        switch (opn) 
        {
            case 1:
                printf("\n Enter element to insert: ");
                scanf("%d", &ele);
                CQinsert(ele);
                break;
            case 2:
                ele = CQdelete();
                if (ele != -1) 
                {
                    printf("\n Deleted element is %d.\n", ele);
                }
                break;
            case 3:
                printf("\n Status of the circular queue: \n");
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\n Invalid Option. \n");
        }
    }
    while (opn != 4);
    return 0;
}
