#include <stdio.h>

/* Function to solve the Towers of Hanoi problem */
void towers(int n, char source, char dest, char auxiliary) 
{

    /* Base case: If there are no disks, do nothing */
    if (n == 0) {
        return;
    }

    /* Move n-1 disks from source to auxiliary using destination as the temporary storage */
    towers(n - 1, source, auxiliary, dest);

    /* Print the move instruction */
    printf("Move disk %d from %c to %c\n", n, source, dest);  // Move the nth disk from the source peg to the destination peg.

    /* Move n-1 disks from auxiliary to destination using source as the temporary storage */
    towers(n - 1, auxiliary, dest, source);
}

/* Main function */
void main() 
{
    int n;

    /* Get the number of disks from the user */
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    /* Solve the Towers of Hanoi problem */
    towers(n, 'A', 'C', 'B');

}
