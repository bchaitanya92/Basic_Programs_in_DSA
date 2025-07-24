#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

// Structure to represent a node in the polynomial linked list
struct node {
    float cf;
    int px, py, pz;
    struct node *link;
};

// Function to allocate memory for a new node
typedef struct node *NODE;

NODE getnode() {
    NODE x = (NODE)malloc(sizeof(struct node));
    if (x == NULL) {
        printf("Out of memory\n");
        exit(0);
    }
    return x;
}

// Function to create a header node for a circular linked list
NODE create_header() {
    NODE head = getnode();
    head->link = head;  // Point to itself to create a circular list
    return head;
}


// Function to insert a new term at the rear of the polynomial
NODE insert_rear(float cf, int px, int py, int pz, NODE head) {
    NODE temp, cur;
    temp = getnode();
    temp->cf = cf;
    temp->px = px;
    temp->py = py;
    temp->pz = pz;

    // Traverse to the last node
    cur = head->link;
    while (cur->link != head) {
        cur = cur->link;
    }

    // Link the new node at the end
    cur->link = temp;
    temp->link = head;
    return head;
}

// Function to display the polynomial
void display(NODE head) {
    NODE temp;
    if (head->link == head) {
        printf("Polynomial doesn't exist\n");
        return;
    }
    temp = head->link;
    while (temp != head) {
        printf(" % 5.2fx^%dy^%dz^%d+", temp->cf, temp->px, temp->py, temp->pz);
        temp = temp->link;
    }
    printf("\n");
}

// Function to add two polynomials
NODE add_poly(NODE h1, NODE h2, NODE h3) {
    NODE p1, p2;
    int x1, x2, y1, y2, z1, z2, cf1, cf2;
    p1 = h1->link;
    while (p1 != h1) {
        x1 = p1->px;
        y1 = p1->py;
        z1 = p1->pz;
        cf1 = p1->cf;
        p2 = h2->link;
        while (p2 != h2) {
            x2 = p2->px;
            y2 = p2->py;
            z2 = p2->pz;
            cf2 = p2->cf;
            if (x1 == x2 && y1 == y2 && z1 == z2) {
                break;      // Matching terms found
            }
            p2 = p2->link;
        }
        if (p2 != h2) {
            cf2 += cf1;     // Combine coefficients of matching terms
            if (cf2 != 0) {
                h3 = insert_rear(cf2, x1, y1, z1, h3);
            }
        } else {
            h3 = insert_rear(cf1, x1, y1, z1, h3);    // Add terms from h1 not in h2
        }
        p1 = p1->link;
    }

    // Add remaining terms from h2
    p2 = h2->link;
    while (p2 != h2) {
        h3 = insert_rear(p2->cf, p2->px, p2->py, p2->pz, h3);
        p2 = p2->link;
    }
    return h3;
}

// Function to read a polynomial from the user
NODE read_poly(NODE head) {
    int i, px, py, pz;
    float cf;
    printf("Enter -999 as coefficient to end the polynomial\n");
    for (i = 1;; i++) {
        printf("Enter term %d\n", i);
        printf("Coefficient: ");
        scanf("%f", &cf);
        if (cf == -999) {
            break;
        }
        printf("Power of x: ");
        scanf("%d", &px);
        printf("Power of y: ");
        scanf("%d", &py);
        printf("Power of z: ");
        scanf("%d", &pz);
        head = insert_rear(cf, px, py, pz, head);
    }
    return head;
}

// Function to represent and evaluate a polynomial
void represent_evaluate()
{
    NODE head = create_header();
    head = read_poly(head);
    printf("Polynomial is:\n");
    display(head);
    printf("Enter the values of x, y, z: ");
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    NODE temp = head->link;
    float sum = 0.0;
    while (temp != head) {
        sum += temp->cf * pow(x, temp->px) * pow(y, temp->py) * pow(z, temp->pz);
        temp = temp->link;
    }
    printf("The total sum is %f\n", sum);
}

// Function to add two polynomials
void polysum() {
    NODE h1 = create_header(), h2 = create_header(), h3 = create_header();
    printf("Enter the first polynomial:\n");
    h1 = read_poly(h1);
    printf("Enter the second polynomial:\n");
    h2 = read_poly(h2);
    h3 = add_poly(h1, h2, h3);
    printf("The first polynomial is:\n");
    display(h1);
    printf("The second polynomial is:\n");
    display(h2);
    printf("The sum of two polynomials is:\n");
    display(h3);
}

// Main function to drive the program
void main() {
    int choice;
    while (1) {
        printf("\n1. Represent & Evaluate\n2. Add Two Polynomials\n3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                represent_evaluate();
                break;
            case 2:
                polysum();
                break;
            case 3:
                exit(0);
            default:
                printf("\nEnter a proper choice.\n");
        }
    }
}
