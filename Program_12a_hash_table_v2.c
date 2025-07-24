#include <stdio.h>
#include <stdlib.h>
#define MAX 5
struct employee {
    int emp_id, emp_age;
    char emp_name[25];
} emp[MAX];
int hash(int key) {
    return key % MAX;
}
void insertRecord() {
    int id, haddr, index, count=0;
    if (count == MAX){
        printf("No free address space\n");return;
    }
    printf("Enter employee id: ");
    scanf("%d", &id);
    haddr = hash(id);
    printf("Home address is %d\n", haddr);
    for (index = 0; index < MAX; index++) {
        int pos = (haddr + index) % MAX;
        if (emp[pos].emp_id == 0) {
            emp[pos].emp_id = id;
            printf("Enter the employee name: ");
            scanf("%s", emp[pos].emp_name);
            printf("Enter the employee age: ");
            scanf("%d", &emp[pos].emp_age);
            count++;
            printf("Successfully inserted at Actual Address: %d\n\n", pos);break;
        }
    }
}
void displayRecords() {
    printf("Employee details are\n");
    for (int index = 0; index < MAX; index++) {
        if (emp[index].emp_id != 0)
            printf("Employee id is %d\tEmployee name is %s\tEmployee age is %d\n", emp[index].emp_id, emp[index].emp_name, emp[index].emp_age);
    }
}
void main() {
    int ch;
    for (;;) {
        printf("\n1. Insert record\n2. Display records\n3. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insertRecord();break;
            case 2:
                displayRecords();break;
            case 3:
                exit(0);
            default:
                printf("\nEnter proper Choice.\n");
        }
    }
}