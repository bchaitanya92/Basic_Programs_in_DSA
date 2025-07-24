#include <stdio.h>
#include <stdlib.h>

struct node {
    char ssn[20], name[20], dept[20], desg[20], phno[20];
    long int sal;
    struct node *llink, *rlink;
};

typedef struct node *NODE;

NODE temp, first = NULL, end = NULL;

// Function to create a new node
NODE getnode(void) {
    NODE x = (NODE)malloc(sizeof(struct node));
    return x;
}

// Function to read employee data
void read(NODE temp) {
    temp->llink = temp->rlink = NULL;
    printf("Enter SSN: ");
    scanf("%s", temp->ssn);
    printf("Enter Name: ");
    scanf("%s", temp->name);
    printf("Enter Department: ");
    scanf("%s", temp->dept);
    printf("Enter Designation: ");
    scanf("%s", temp->desg);
    printf("Enter PhoneNo: ");
    scanf("%s", temp->phno);
    printf("Enter Salary: ");
    scanf("%ld", &temp->sal);
}

// Function to create DLL using end insertion
void create_dll(void) {
    int n, i = 0;
    printf("Enter the number of Employees: ");
    scanf("%d", &n);
    while (i != n) {
        i++;
        printf("Enter details for Employee %d\n", i);
        temp = getnode();
        read(temp);
        if (first == NULL) {
            first = end = temp;
        } else {
            end->rlink = temp;
            temp->llink = end;
            end = temp;
        }
    }
    printf("[+] DONE\n");
}

// Function to display DLL and count nodes
void displaycount(void) {
    NODE temp1 = first;
    int count = 0;
    if (temp1 == NULL) {
        printf("[!] List is empty\n");
    } else {
        printf("\nSSN\tName\tDEPT\tDESIG\tPhone\t\tSalary\n");
        printf(" -\t- \t -\t- \t- \t\t- \n");
        while (temp1 != NULL) {
            count++;
            printf("%s\t%s\t%s\t%s\t%s\t%ld\n", temp1->ssn, temp1->name, temp1->dept, temp1->desg, temp1->phno, temp1->sal);
            temp1 = temp1->rlink;
        }
        printf("\nCount: %d\n", count);
    }
}

// Function to insert at the front of DLL
void insertfront(void) {
    temp = getnode();
    read(temp);
    if (first == NULL) {
        first = end = temp;
    } else {
        temp->rlink = first;
        first->llink = temp;
        first = temp;
    }
}

// Function to insert at the end of DLL
void insertend(void) {
    temp = getnode();
    read(temp);
    if (first == NULL) {
        first = end = temp;
    } else {
        end->rlink = temp;
        temp->llink = end;
        end = temp;
    }
}

// Function to delete from the front of DLL
void deletefront(void) {
    NODE temp2 = first;
    if (temp2 == NULL) {
        printf("[!] List is empty\n");
    } else {
        printf("[+] Deleted record %s\n", temp2->ssn);
        first = first->rlink;
        if (first == NULL) {  // If list becomes empty
            end = NULL;
        } else {
            first->llink = NULL;
        }
        free(temp2);
    }
}

// Function to delete from the end of DLL
void deleteend(void) {
    NODE temp2 = end;
    if (temp2 == NULL) {
        printf("[!] List is empty\n");
    } else {
        printf("[+] Deleted record %s\n", temp2->ssn);
        end = end->llink;
        if (end == NULL) {  // If list becomes empty
            first = NULL;
        } else {
            end->rlink = NULL;
        }
        free(temp2);
    }
}

int main(void) {
    int ch;
    while (1) {
        printf("\nMENU\n----- \n[1] Create list\n[2] Display list\n[3] Insert front\n[4] Insert end\n[5] Delete front\n[6] Delete end\n[7] Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                create_dll();
                break;
            case 2:
                displaycount();
                break;
            case 3:
                insertfront();
                break;
            case 4:
                insertend();
                break;
            case 5:
                deletefront();
                break;
            case 6:
                deleteend();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
