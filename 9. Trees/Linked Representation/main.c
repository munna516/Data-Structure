#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
} *root = NULL;

struct node *CreateNode(int value)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = value;
    new_node->lchild = NULL;
    new_node->rchild = NULL;
    return new_node;
}

void Create(struct node *t)
{
    struct node *p, *t_node;
    int r;
    printf("Enter Root : ");
    scanf("%d", &r);
    root = CreateNode(r);

    struct node *q[100]; // Assuming a maximum of 100 nodes
    int front = -1, rear = -1;
    q[++rear] = root;

    while (front != rear)
    {
        p = q[++front];
        int lc, rc;
        printf("Enter the left child of %d : ", p->data);
        scanf("%d", &lc);
        if (lc != -1)
        {
            t_node = CreateNode(lc);
            p->lchild = t_node;
            q[++rear] = t_node;
        }

        printf("Enter the right child of %d : ", p->data);
        scanf("%d", &rc);
        if (rc != -1)
        {
            t_node = CreateNode(rc);
            p->rchild = t_node;
            q[++rear] = t_node;
        }
    }
}

void Inorder(struct node *p)
{
    if (p == NULL)
        return;
    Inorder(p->lchild);
    printf("%d ", p->data);
    Inorder(p->rchild);
}

void Preorder(struct node *p)
{
    if (p == NULL)
        return;
    printf("%d ", p->data);
    Preorder(p->lchild);
    Preorder(p->rchild);
}

void Postorder(struct node *p)
{
    if (p == NULL)
        return;
    Postorder(p->lchild);
    Postorder(p->rchild);
    printf("%d ", p->data);
}

int main()
{
    struct node t;
    Create(&t);
    printf("Inorder : ");
    Inorder(root);
    printf("\nPreorder : ");
    Preorder(root);
    printf("\nPostorder : ");
    Postorder(root);

    return 0;
}
