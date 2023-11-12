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

    node *CreateNode(int value)
    {
        node *new_node = new node;
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
    void Create()
    {
        node *p, *t;
        queue<node *> q;
        int r;
        cout << "Enter Root : ";
        cin >> r;
        root = CreateNode(r);
        q.push(root);
        while (!q.empty())
        {
            p = q.front();
            q.pop();
            int lc, rc;
            cout << "Enter the left child of " << p->data << " : ";
            cin >> lc;
            if (lc != -1)
            {
                t = CreateNode(lc);
                p->lchild = t;
                q.push(t);
            }
            cout << "Enter the right child " << p->data << " : ";
            cin >> rc;
            if (rc != -1)
            {
                t = CreateNode(rc);
                p->rchild = t;
                q.push(t);
            }
        }
    }

    void Inorder(node *p)
    {
        if (p == NULL)
            return;
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }

    void Preorder(node *p)
    {
        if (p == NULL)
            return;
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
    void Postorder(node *p)
    {
        if (p == NULL)
            return;
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
    }

    void IterativePreorder(node *p)
    {
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

    void IterativeInorder(node *p)
    {
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
                temp = (int)st.top();
                st.pop();
                if (temp > 0)
                {
                    st.push((node *)-temp);
                    p = p->rchild;
                }
                else
                {
                    cout << p->data << " ";
                    p = NULL;
                }
            }
        }
    }
};
int main()
{
    Tree t;
    t.Create();
    cout << "Inorder : ";
    t.Inorder(t.root);
    cout << "\nIterative Inorder : ";
    t.IterativeInorder(t.root);
    cout << "\nPreorder : ";
    t.Preorder(t.root);
    cout << "\nIterative Preorder : ";
    t.IterativePreorder(t.root);
    cout << "\nPostorder : ";
    t.Postorder(t.root);
    cout << "\nIterative PostOrder : ";
    t.IterativePostorder(t.root);

    return 0;
}