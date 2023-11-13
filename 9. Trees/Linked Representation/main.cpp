#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    node *lchild;
    int data;
    node *rchild;
};
class Tree
{
public:
    node *root;
    Tree()
    {
        root = NULL;
    }

    // Creating Node
    node *CreateNode(int dataue)
    {
        node *newNode = new node;
        if (newNode == NULL)
        {
            printf("Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        newNode->data = dataue;
        newNode->lchild = NULL;
        newNode->rchild = NULL;
        return newNode;
    }

    // Create Tree
    void CreateTree()
    {
        queue<node *> q;
        int r;
        cout << "Enter root : ";
        cin >> r;
        root = CreateNode(r);
        node *p, *t;
        q.push(root);
        while (!q.empty())
        {
            p = q.front();
            q.pop();
            int lc, rc;
            cout << "Enter lchild child of " << p->data << " : ";
            cin >> lc;
            if (lc != -1)
            {
                t = CreateNode(lc);
                p->lchild = t;
                q.push(t);
            }
            cout << "Enter rchild child of " << p->data << " : ";
            cin >> rc;
            if (rc != -1)
            {
                t = CreateNode(rc);
                p->rchild = t;
                q.push(t);
            }
        }
    }

    // Preorder Traversal
    void Preorder(node *p)
    {
        if (p == NULL)
            return;
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }

    // Inorder Traversal
    void Inorder(node *p)
    {
        if (p == NULL)
            return;
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }

    // Postorder Traversal
    void Postorder(node *p)
    {
        if (p == NULL)
            return;
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
    }

    // Iterative Preorder
    void IterativePreorder(node *p)
    {
        if (p == NULL)
            return;
        stack<node *> st;
        while (p != NULL || !st.empty())
        {
            if (p != NULL)
            {
                cout << p->data << " ";
                st.push(p);
                p = p->lchild;
            }
            else
            {
                p = st.top();
                st.pop();

                p = p->rchild;
            }
        }
    }

    // Iterative Inorder
    void IterativeInorder(node *p)
    {
        if (p == NULL)
            return;
        stack<node *> st;
        while (p != NULL || !st.empty())
        {
            if (p != NULL)
            {
                st.push(p);
                p = p->lchild;
            }
            else
            {
                p = st.top();
                st.pop();
                cout << p->data << " ";
                p = p->rchild;
            }
        }
    }

    // Iterative Postorder
    void IterativePostorder(node *p)
    {
        stack<node *> st;
        long long temp;
        while (p != NULL || !st.empty())
        {
            if (p != NULL)
            {
                st.push(p);
                p = p->lchild;
            }
            else
            {
                temp = (long long)st.top();
                st.pop();
                if (temp > 0)
                {
                    st.push((node *)-temp);
                    p = ((node *)temp)->rchild;
                }
                else
                {
                    cout << ((node *)-temp)->data << " ";
                    p = NULL;
                }
            }
        }
    }
};
int main()
{
    Tree t;
    t.CreateTree();
    cout << "\nPreorder : \n";
    t.Preorder(t.root);
    cout << endl;
    t.IterativePreorder(t.root);
    cout << "\nInorder : \n";
    t.Inorder(t.root);
    cout << endl;
    t.IterativeInorder(t.root);
    cout << "\nPostorder : \n";
    t.Postorder(t.root);
    cout << endl;
    t.IterativePostorder(t.root);

    return 0;
}

/*
5
1
6
4
3
8
-1
-1
-1
-1
-1
-1
-1
*/