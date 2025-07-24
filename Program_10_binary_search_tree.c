#include<stdio.h>
#include<stdlib.h>

#define MAX 10

// Define a structure for the binary tree node
struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};

// Define a typedef for easier use of struct node pointer
typedef struct node *NODE;

// Function to allocate memory for a new node
NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("Out of memory");
        exit(0);
    }
    return x;
}

// Function to insert a new node with given item into the BST
NODE insert(int item, NODE root)
{
    NODE temp, cur, prev;
    temp = getnode();
    temp->info = item;
    temp->llink = temp->rlink = NULL;

    // If the tree is empty, make the new node as the root
    if (root == NULL)
    {
        root = temp;
        return root;
    }
    else
    {
        prev = NULL;
        cur = root;

        // Traverse the tree to find the appropriate position for the new node
        while (cur != NULL)
        {
            prev = cur;
            cur = (temp->info < cur->info) ? cur->llink : cur->rlink;
        }

        // Insert the new node at the appropriate position
        if (temp->info < prev->info)
            prev->llink = temp;
        else
            prev->rlink = temp;

        return root;
    }
}

// Function to perform preorder traversal of the BST
void pre(NODE PRE)
{
    if (PRE != NULL)
    {
        printf("%d\t", PRE->info);
        pre(PRE->llink);
        pre(PRE->rlink);
    }
    return;
}

// Function to perform inorder traversal of the BST
void in(NODE IN)
{
    if (IN != NULL)
    {
        in(IN->llink);
        printf("%d\t", IN->info);
        in(IN->rlink);
    }
    return;
}

// Function to perform postorder traversal of the BST
void post(NODE POST)
{
    if (POST != NULL)
    {
        post(POST->llink);
        post(POST->rlink);
        printf("%d\t", POST->info);
    }
    return;
}

// Function to perform all three traversals and print the result
void traversal(NODE root)
{
    NODE IN, PRE, POST;
    IN = root;
    PRE = root;
    POST = root;

    // Check if the tree is empty
    if (root == NULL)
    {
        printf("Empty tree\n");
        return;
    }

    printf("Preorder traversal: ");
    pre(PRE);
    printf("\nInorder traversal: ");
    in(IN);
    printf("\nPostorder traversal: ");
    post(POST);

    return;
}

// Function to search for an element in the BST
void search(NODE root)
{
    int item, flag = 0;
    NODE cur;
    printf("Enter element to be searched: ");
    scanf("%d", &item);

    // Check if the tree is empty
    if (root == NULL)
    {
        printf("Empty tree\n");
        return;
    }

    cur = root;

    // Traverse the tree to search for the element
    while (cur != NULL)
    {
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

// Main function to drive the program
void main()
{
    int choice, item;
    NODE root = NULL;

    // Menu-driven loop
    while (1)
    {
        printf("\n1 Create BST\n2 Traverse\n3 Search\n4 Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter item to be inserted: ");
            scanf("%d", &item);
            root = insert(item, root);
            break;
        case 2:
            traversal(root);
            break;
        case 3:
            search(root);
            break;
        case 4:
            exit(0);
        default:
            printf("Enter a valid choice\n");
        }
    }
}
