#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct node
{
    int info;
    struct node *llink,*rlink;
};
typedef struct node *NODE;
NODE getnode(){
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL)
        printf("Out of memory");exit(0);
    return x;
}
NODE insert(int item, NODE root){
    NODE temp, cur, prev;
    temp = getnode();
    temp->info = item;
    temp->llink = temp->rlink = NULL;
    if (root == NULL){
        root = temp;return root;
    }
    else{
        prev = NULL;
        cur = root;
        while (cur != NULL){
            prev = cur;
            cur = (temp->info < cur->info) ? cur->llink : cur->rlink;
        }
        if (temp->info < prev->info)
            prev->llink = temp;
        else
            prev->rlink = temp;
        return root;
    }
}
void pre(NODE PRE){
    if (PRE != NULL){
        printf("%d\t", PRE->info);
        pre(PRE->llink);
        pre(PRE->rlink);
    }
    return;
}
void in(NODE IN){
    if (IN != NULL){
        in(IN->llink);
        printf("%d\t", IN->info);
        in(IN->rlink);
    }
    return;
}
void post(NODE POST){
    if (POST != NULL){
        post(POST->llink);
        post(POST->rlink);
        printf("%d\t", POST->info);
    }
    return;
}
void traversal(NODE root){
    NODE IN, PRE, POST;
    IN = root;
    PRE = root;
    POST = root;
    if (root == NULL)
        printf("Empty tree\n");return;
    printf("Preorder traversal: ");
    pre(PRE);
    printf("\nInorder traversal: ");
    in(IN);
    printf("\nPostorder traversal: ");
    post(POST);
    return;
}
void search(NODE root){
    int item, flag = 0;
    NODE cur;
    printf("Enter element to be searched: ");
    scanf("%d", &item);
    if (root == NULL){
        printf("Empty tree\n");
        return;
    }
    cur = root;
    while (cur != NULL){
        if (item == cur->info)
            flag = 1;
        if (item < cur->info)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }
    if (flag == 1)
        printf("Key found\n");
    else
        printf("Key not found\n");

    return;
}
void main(){
    int choice, item;
    NODE root = NULL;
    while (1){
        printf("\n1 Create BST\n2 Traverse\n3 Search\n4 Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice){
        case 1:
            printf("Enter item to be inserted: ");
            scanf("%d", &item);
            root = insert(item, root);break;
        case 2:
            traversal(root);break;
        case 3:
            search(root);break;
        case 4:
            exit(0);
        default:
            printf("Enter a valid choice\n");
        }
    }
}