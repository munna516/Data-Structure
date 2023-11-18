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

    // Recursive Insert
    node *RInsert(node *p, int key)
    {
        node *t = NULL;
        if (p == NULL)
        {
            t = CreateNode(key);
            return t;
        }
        if (key < p->data)
            p->lchild = RInsert(p->lchild, key);
        else if (key > p->data)
            p->rchild = RInsert(p->rchild, key);
        return p;
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

    // Height of a tree
    int Height(node *p)
    {
        int x, y;
        if (p == NULL)
            return 0;
        x = Height(p->lchild);
        y = Height(p->rchild);
        return max(x, y) + 1;
    }

    // Inorder Predecissor
    node *Inpre(node *p)
    {
        while (p && p->rchild != NULL)
            p = p->rchild;
        return p;
    }

    // Inorder Succosor
    node *InSucc(node *p)
    {
        while (p && p->lchild != NULL)
            p = p->lchild;
        return p;
    }

    // Delete a Node
    node *Delete(node *p, int key)
    {
        node *q = NULL;
        if (p == NULL)
            return NULL;
        if (p->lchild == NULL && p->rchild == NULL)
        {
            if (p == root)
                root = NULL;
            delete (p);
            return NULL;
        }
        if (key < p->data)
            p->lchild = Delete(p->lchild, key);
        else if (key > p->data)
            p->rchild = Delete(p->rchild, key);
        else
        {
            if (Height(p->lchild) > Height(p->rchild))
            {
                q = Inpre(p->lchild);
                p->data = q->data;
                p->lchild = Delete(p->lchild, q->data);
            }
            else
            {
                q = InSucc(p->rchild);
                p->data = q->data;
                p->rchild = Delete(p->rchild, q->data);
            }
        }
        return p;
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

    // Generate BST from Preorder O(N)
    void CreatePre(int ar[], int n)
    {
        stack<node *> st;
        node *p = NULL, *t = NULL;
        root = CreateNode(ar[0]);
        p = root;
        int i = 1;
        while (i < n)
        {
            if (ar[i] < p->data)
            {
                t = CreateNode(ar[i]);
                i++;
                p->lchild = t;
                st.push(p);
                p = t;
            }
            else
            {
                while (!st.empty() && ar[i] > st.top()->data)
                {
                    p = st.top();
                    st.pop();
                }
                t = CreateNode(ar[i]);
                i++;
                p->rchild = t;
                p = t;
            }
        }
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
    t.Delete(t.root, 5);
    t.Inorder(t.root);
    cout << endl;
    int ar[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int n = 8;
    t.CreatePre(ar, n);
    t.Inorder(t.root);
    return 0;
}