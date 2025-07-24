#include <stdio.h>
#include <stdlib.h>
struct node {
    char ssn[20], name[20], dept[20], desg[20], phno[20];
    long int sal;
    struct node *llink, *rlink;
};
typedef struct node *NODE;
NODE first = NULL, end = NULL;
NODE getnode(void) {
    return (NODE)malloc(sizeof(struct node));
}
void read(NODE temp) {
    temp->llink = temp->rlink = NULL;
    printf("Enter SSN: "); scanf("%s", temp->ssn);
    printf("Enter Name: "); scanf("%s", temp->name);
    printf("Enter Department: "); scanf("%s", temp->dept);
    printf("Enter Designation: "); scanf("%s", temp->desg);
    printf("Enter PhoneNo: "); scanf("%s", temp->phno);
    printf("Enter Salary: "); scanf("%ld", &temp->sal);
}
void create_dll(void) {
    int n, i = 0;   
    printf("Enter the number of Employees: ");
    scanf("%d", &n);
    while (i != n) {
        i++;
        printf("Enter details for Employee %d\n", i);
        NODE temp = getnode();
        read(temp);
        if (!first)
            first = end = temp;
        else {
            end->rlink = temp;
            temp->llink = end;
            end = temp;
        }
    }
    printf("[+] DONE\n");
}
void displaycount(void) {
    NODE temp1 = first;
    int count = 0;
    if (!temp1)
        printf("[!] List is empty\n");
    else {
        printf("\nSSN\tName\tDEPT\tDESIG\tPhone\t\tSalary\n");
        while (temp1) {
            count++;
            printf("%s\t%s\t%s\t%s\t%s\t%ld\n", temp1->ssn, temp1->name, temp1->dept, temp1->desg, temp1->phno, temp1->sal);
            temp1 = temp1->rlink;
        }
        printf("\nCount: %d\n", count);
    }
}
void insertfront(void) {
    NODE temp = getnode();
    read(temp);
    if (!first)
        first = end = temp;
    else {
        temp->rlink = first;
        first->llink = temp;
        first = temp;
    }
}
void insertend(void) {
    NODE temp = getnode();
    read(temp);
    if (!first)
        first = end = temp;
    else {
        end->rlink = temp;
        temp->llink = end;
        end = temp;
    }
}
void deletefront(void) {
    NODE temp2 = first;
    if (!temp2)
        printf("[!] List is empty\n");
    else {
        printf("[+] Deleted record %s\n", temp2->ssn);
        first = first->rlink;
        if (!first)
            end = NULL;
        else
            first->llink = NULL;
        free(temp2);
    }
}
void deleteend(void) {
    NODE temp2 = end;
    if (!temp2)
        printf("[!] List is empty\n");
    else {
        printf("[+] Deleted record %s\n", temp2->ssn);
        end = end->llink;
        if (!end)
            first = NULL;
        else
            end->rlink = NULL;
        free(temp2);
    }
}
int main(void) {
    int ch;
    printf("\nMENU\n----- \n[1] Create list\n[2] Display list\n[3] Insert front\n[4] Insert end\n[5] Delete front\n[6] Delete end\n[7] Exit\n");
    while (1) {
        printf("Enter the choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:create_dll();break;
            case 2:displaycount();break;
            case 3:insertfront();break;
            case 4:insertend();break;
            case 5:deletefront();break;
            case 6:deleteend();break;
            case 7:exit(0);
            default:printf("Invalid choice\n");
        }
    }
}