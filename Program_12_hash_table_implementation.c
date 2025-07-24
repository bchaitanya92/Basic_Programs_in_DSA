#include <stdio.h>
#include <stdlib.h>
#define MAX_ADDR 5

// Employee structure definition
struct employee {
    int emp_id, emp_age;
    char emp_name[25];
} emp[MAX_ADDR];

// Hash function to determine the home address
int hash(int key) {
    return key % MAX_ADDR;
}

// Function to insert an employee record
void insertRecord() {
    int id, haddr, index, count=0;

    if (count == MAX_ADDR) {
        printf("No free address space\n");
        return;
    }

    printf("Enter employee id: ");
    scanf("%d", &id);

    haddr = hash(id);
    printf("Home address is %d\n", haddr);

    for (index = 0; index < MAX_ADDR; index++) {
        int pos = (haddr + index) % MAX_ADDR;

        if (emp[pos].emp_id == 0) {
            emp[pos].emp_id = id;
            printf("Enter the employee name: ");
            scanf("%s", emp[pos].emp_name);
            printf("Enter the employee age: ");
            scanf("%d", &emp[pos].emp_age);
            count++;
            printf("Successfully inserted at Actual Address: %d\n\n", pos);
            break;
        }
    }
}

// Function to display all employee records
void displayRecords() {
    printf("Employee details are\n");

    for (int index = 0; index < MAX_ADDR; index++) {
        if (emp[index].emp_id != 0) {
            printf("Employee id is %d\t", emp[index].emp_id);
            printf("Employee name is %s\t", emp[index].emp_name);
            printf("Employee age is %d\n", emp[index].emp_age);
        }
    }
}

// Global variables
int count = 0;

// Main function
void main() {
    int ch;

    // Menu-driven loop
    for (;;) {
        printf("\n1. Insert record\n2. Display records\n3. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insertRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                exit(0);
            default:
                printf("\nEnter proper Choice.\n");
        }
    }
}
