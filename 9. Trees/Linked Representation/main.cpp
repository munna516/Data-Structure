#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

class Tree
{
public:
    struct Node *root = NULL;
    // Creating Binary Tree
    Node *Create()
    {
        int x;
        struct Node *newnode;
        newnode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the value(-1 for NULL ) : ");
        scanf("%d", &x);
        if (x == -1)
            return 0;
        newnode->data = x;
        printf("Enter the Left Child of %d\n", x);
        newnode->lchild = Create();
        printf("Enter the Right Child of %d\n", x);
        newnode->rchild = Create();
        return newnode;
    }

    // Tree Traversal (Preorder)
    void Preorder(Node *root)
    {
        if (root == NULL)
            return;
        printf("%d ", root->data);
        Preorder(root->lchild);
        Preorder(root->rchild);
    }

    // Tree Traversal (Inorder)
    void Inorder(Node *root)
    {
        if (root == NULL)
            return;
        Inorder(root->lchild);
        printf("%d ", root->data);
        Inorder(root->rchild);
    }
    // Tree Traversal (Postorder)
    void Postorder(Node *root)
    {
        if (root == NULL)
            return;
        Postorder(root->lchild);
        Postorder(root->rchild);
        printf("%d ", root->data);
    }
};

int main()
{
    Tree t;
    t.root = t.Create();
    printf("\nPreorder : ");
    t.Preorder(t.root);
    printf("\nInorder : ");
    t.Inorder(t.root);
    printf("\nPostorder : ");
    t.Postorder(t.root);
}