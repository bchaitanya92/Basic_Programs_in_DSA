#include <stdio.h>
#include <stdlib.h>
typedef struct stud {
    char usn[30], name[30], branch[30], phone[30];
    int sem;
    struct stud *next;
} node;
node *start = NULL;
node* getnode() {
    node *new1 = (node *)malloc(sizeof(node));
    if (!new1) {
        printf("Out of memory\n");
        exit(1);
    }
    printf("Enter the student\nUsn\nName\nBranch\nSemester\nPhone Number\n");
    if (scanf("%s %s %s %d %s", new1->usn, new1->name, new1->branch, &new1->sem, new1->phone) != 5) {
        printf("Invalid input format. Exiting...\n");
        exit(1);
    }
    new1->next = NULL;
    while ((getchar()) != '\n');  // Clear input buffer
    return new1;
}
void display() {
    node *temp = start;
    int count = 0;
    if (!start) {
        printf("List Empty\n");
        return;
    }
    printf("\nUSN\tName\tBranch\t\tSemester\t\tPhone Number\n");
    while (temp) {
        printf("%s\t%s\t%s\t\t%d\t\t%s\n", temp->usn, temp->name, temp->branch, temp->sem, temp->phone);
        temp = temp->next;
        count++;
    }
    printf("The number of nodes are: %d\n", count);
}
void insert_front() {
    node *new1 = getnode();
    new1->next = start;
    start = new1;
}
void createSLL() {
    int n, i = 0;
    printf("Enter the number of students to be created\n");
    scanf("%d", &n);
    while (i < n) {
        i++;
        insert_front();
    }
}

void insert_end() {
    node *new1 = getnode();
    if (!start) {
        start = new1;
        return;
    }
    node *temp = start;
    while (temp->next)
        temp = temp->next;
    temp->next = new1;
}
void del_front() {
    if (!start) {
        printf("List is empty\n");
        return;
    }
    node *temp = start;
    start = start->next;
    printf("The node of student usn %s is deleted\n", temp->usn);
    free(temp);
}
void del_end() {
    if (!start) {
        printf("List is empty\n");
        return;
    }
    node *cur = start, *pre = NULL;
    while (cur->next) {
        pre = cur;
        cur = cur->next;
    }
    if (!pre)
        start = NULL;
    else
        pre->next = NULL;
    printf("The node of student usn %s is deleted\n", cur->usn);
    free(cur);
}
void main() {
    int ch;
    for (;;) {
        printf("\n1:Create SLL\n2:Insert Front\n3:Insert End\n4:Delete Front\n5:Delete End\n6:Display\n7:Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:createSLL();break;
            case 2:insert_front();break;
            case 3:insert_end();break;
            case 4:del_front();break;
            case 5:del_end();break;
            case 6:display();break;
            case 7:exit(0);
            default: printf("Invalid option\n");break;
        }
    }
}