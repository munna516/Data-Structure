#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    node *lchild;
    int data;
    node *rchild;
};
class Binary_Search_Tree
{
public:
    node *root;
    Binary_Search_Tree()
    {
        root = NULL;
    }

    // Create Node
    node *CreateNode(int value)
    {
        node *t = new node;
        t->data = value;
        t->lchild = t->rchild = NULL;
        return t;
    }

    // Inserting Node
    void Insert(int value)
    {
        node *p, *t = root, *r = NULL;
        if (root == NULL)
        {
            p = CreateNode(value);
            root = p;
            return;
        }
        while (t != NULL)
        {
            r = t;
            if (value > t->data)
                t = t->rchild;
            else if (value < t->data)
                t = t->lchild;
            else
                return;
        }
        p = CreateNode(value);
        if (value > r->data)
            r->rchild = p;
        else
            r->lchild = p;
    }

    // Search element
    node *Search(int value)
    {
        node *p = root;
        while (p != NULL)
        {
            if (value == p->data)
                return p;
            else if (value > p->data)
                p = p->rchild;
            else
                p = p->lchild;
        }
        return NULL;
    }
    //  Inorder Treversal
    void Inorder(node *p)
    {
        if (p == NULL)
            return;
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
};
int main()
{
    Binary_Search_Tree t;
    t.Insert(10);
    t.Insert(5);
    t.Insert(20);
    t.Insert(8);
    t.Insert(30);
    t.Inorder(t.root);
    cout << endl;
    node *temp = t.Search(21);
    if (temp)
        cout << "Element " << temp->data << " is found " << endl;
    else
        cout << "Element is not found" << endl;
    return 0;
}