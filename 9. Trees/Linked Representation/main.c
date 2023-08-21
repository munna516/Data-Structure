#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
} *root = NULL;

// Creating Binary Tree
struct Node *Create()
{
    int x;
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the value(-1 for NULL ) : ");
    scanf("%d", &x);
    if (x == -1)
        return NULL;
    newnode->data = x;
    printf("Enter the Left Child of %d\n", x);
    newnode->lchild = Create();
    printf("Enter the Right Child of %d\n", x);
    newnode->rchild = Create();
    return newnode;
}

// Tree Traversal (Preorder)
void Preorder(struct Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    Preorder(root->lchild);
    Preorder(root->rchild);
}

// Tree Traversal (Inorder)
void Inorder(struct Node *root)
{
    if (root == NULL)
        return;
    Inorder(root->lchild);
    printf("%d ", root->data);
    Inorder(root->rchild);
}

// Tree Traversal (Postorder)
void Postorder(struct Node *root)
{
    if (root == NULL)
        return;
    Postorder(root->lchild);
    Postorder(root->rchild);
    printf("%d ", root->data);
}

// Count of Nodes in Tree
int CountOfNodes(struct Node *root)
{
    if (root == NULL)
        return 0;
    return CountOfNodes(root->lchild) + CountOfNodes(root->rchild) + 1;
}

// Sum of all nodes
int SumofNodes(struct Node *root)
{
    if (root == NULL)
        return 0;
    return (root->data + SumofNodes(root->lchild) + SumofNodes(root->rchild));
}
int main()
{
    root = Create();
    printf("\nPreorder : ");
    Preorder(root);
    printf("\nInorder : ");
    Inorder(root);
    printf("\nPostorder : ");
    Postorder(root);
    printf("\n");
    printf("Total Nodes : %d\n", CountOfNodes(root));
    printf("Sum of  Nodes : %d\n", SumofNodes(root));
}