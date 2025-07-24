#include <stdio.h>
#include <stdlib.h>
#define size 5
int CQ[size], f = -1, r = -1;
int CQfull() {
    return (f == (r + 1) % size);
}
int CQempty() {
    return (f == -1);
}
void CQinsert(int ele) {
    if (CQfull()) {
        printf("\n Queue Overflow!!!\n");
    } else {
        if (CQempty()) f = 0;
        r = (r + 1) % size;
        CQ[r] = ele;
    }
}
int CQdelete() {
    int ele;
    if (CQempty()) {
        printf("\n Queue Underflow!!!\n");
        return -1;
    } else {
        ele = CQ[f];
        if (f == r) f = r = -1;
        else f = (f + 1) % size;
        return ele;
    }
}
void display() {
    int i;
    if (CQempty()) printf("\n Queue is Empty.\n");
    else {
        printf("front[%d]->", f);
        for (i = f; i != r; i = (i + 1) % size) printf(" %d ", CQ[i]);
        printf(" %d ", CQ[i]);
        printf("<-[%d]rear", r);
    }
}
void main() {
    int opn, ele;
    do {
        printf("\n\n Circular QUEUE Operations\n");
        printf("\n 1. Insert\n 2. Delete\n 3. Display\n 4. Exit\n");
        printf("\n Your option: ");
        scanf("%d", &opn);
        switch (opn) {
            case 1:
                printf("\n Enter element to insert: ");
                scanf("%d", &ele);
                CQinsert(ele);
                break;
            case 2:
                ele = CQdelete();
                if (ele != -1) printf("\n Deleted element is %d.\n", ele);
                break;
            case 3:
                printf("\n Status of the circular queue: \n");
                display();break;
            case 4:
                exit(0);break;
            default:
                printf("\n Invalid Option. \n");
        }
    } while (opn != 4);
}