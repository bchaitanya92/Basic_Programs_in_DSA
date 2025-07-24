#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node {
    float cf;
    int px, py, pz;
    struct node *link;
};
typedef struct node *NODE;
NODE getnode() {
    NODE x = (NODE)malloc(sizeof(struct node));
    if (x == NULL) {
        printf("Out of memory\n");
        exit(0);
    }
    return x;
}
NODE create_header() {
    NODE head = getnode();
    head->link = head;
    return head;
}
NODE insert_rear(float cf, int px, int py, int pz, NODE head) {
    NODE temp = getnode();
    temp->cf = cf;
    temp->px = px;
    temp->py = py;
    temp->pz = pz;
    NODE cur = head->link;
    while (cur->link != head) cur = cur->link;
    cur->link = temp;
    temp->link = head;
    return head;
}
void display(NODE head) {
    NODE temp = head->link;
    while (temp != head) {
        printf(" % 5.2fx^%dy^%dz^%d+", temp->cf, temp->px, temp->py, temp->pz);
        temp = temp->link;
    }
    printf("\n");
}
NODE add_poly(NODE h1, NODE h2, NODE h3) {
    NODE p1, p2;
    int x1, x2, y1, y2, z1, z2, cf1, cf2;
    p1 = h1->link;
    while (p1 != h1) {
        x1 = p1->px, y1 = p1->py, z1 = p1->pz, cf1 = p1->cf;
        p2 = h2->link;
        while (p2 != h2 && (x2 = p2->px, y2 = p2->py, z2 = p2->pz, cf2 = p2->cf, !(x1 == x2 && y1 == y2 && z1 == z2)))
            p2 = p2->link;
        if (p2 != h2) cf2 += cf1;
        h3 = insert_rear(cf2 != 0 ? cf2 : cf1, x1, y1, z1, h3);
        p1 = p1->link;
    }
    p2 = h2->link;
    while (p2 != h2) {
        h3 = insert_rear(p2->cf, p2->px, p2->py, p2->pz, h3);
        p2 = p2->link;
    }
    return h3;
}
NODE read_poly(NODE head) {
    float cf;
    int px, py, pz, i = 0;
    printf("Enter -999 as coefficient to end the polynomial\n");
    while (printf("Enter term %d\nCoefficient: ", ++i) && scanf("%f", &cf), cf != -999)
        head = insert_rear(cf, scanf("%d", &px), scanf("%d", &py), scanf("%d", &pz), head);
    return head;
}
void represent_evaluate() {
    NODE head = create_header();
    head = read_poly(head);
    printf("Polynomial is:\n");
    display(head);
    int x, y, z;
    printf("Enter the values of x, y, z: ");
    scanf("%d %d %d", &x, &y, &z);
    NODE temp = head->link;
    float sum = 0.0;
    while (temp != head) sum += temp->cf * pow(x, temp->px) * pow(y, temp->py) * pow(z, temp->pz), temp = temp->link;
    printf("The total sum is %f\n", sum);
}
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
void main() {
    int choice;
    while (1) {
        printf("\n1. Represent & Evaluate\n2. Add Two Polynomials\n3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:represent_evaluate();break;
            case 2:polysum();break;
            case 3:exit(0);
            default:printf("\nEnter a proper choice.\n");
        }
    }
}