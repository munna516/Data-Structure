#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    node *lchild;
    int data;
    int height;
    node *rchild;
};
class AVL_Tree
{
public:
    node *root;
    AVL_Tree()
    {
        root = NULL;
    }

    // Height of a node
    int NodeHeight(node *p)
    {
        int hl, hr;
        hl = (p && p->lchild) ? p->lchild->height : 0;
        hr = (p && p->rchild) ? p->rchild->height : 0;
        return max(hl, hr) + 1;
    }

    // Balance Factor
    int BalanceFactor(node *p)
    {
        int hl, hr;
        hl = (p && p->lchild) ? p->lchild->height : 0;
        hr = (p && p->rchild) ? p->rchild->height : 0;
        return hl - hr;
    }

    // LL Rotations
    node *LLRotation(node *p)
    {
        node *pl = p->lchild;
        node *plr = pl->rchild;

        pl->rchild = p;
        p->lchild = plr;
        p->height = NodeHeight(p);
        pl->height = NodeHeight(pl);
        if (root == p)
            root = pl;
        return pl;
    }

    // LR Rotations
    node *LRRotation(node *p)
    {
        node *pl = p->lchild;
        node *plr = pl->rchild;

        pl->rchild = plr->lchild;
        p->lchild = plr->rchild;
        plr->lchild = pl;
        plr->rchild = p;
        p->height = NodeHeight(p);
        pl->height = NodeHeight(pl);
        plr->height = NodeHeight(plr);
        if (root = p)
            root = plr;
        return plr;
    }

    // RR Rotations
    node *RRRotation(node *p)
    {
        node *pr = p->rchild;
        node *prl = pr->lchild;

        pr->lchild = p;
        p->rchild = prl;
        p->height = NodeHeight(p);
        pr->height = NodeHeight(pr);
        if (root == p)
            root = pr;
        return pr;
    }

    // RL Rotations
    node *RLRotation(node *p)
    {
        node *pr = p->rchild;
        node *prl = pr->lchild;

        p->rchild = prl->lchild;
        pr->lchild = prl->rchild;
        prl->lchild = p;
        prl->rchild = pr;
        p->height = NodeHeight(p);
        pr->height = NodeHeight(pr);
        prl->height = NodeHeight(prl);
        if (root = p)
            root = prl;
        return prl;
    }

    // Insert
    node *RInsert(node *p, int key)
    {
        node *t = NULL;
        if (p == NULL)
        {
            t = new node;
            t->data = key;
            t->height = 1;
            t->lchild = t->rchild = NULL;
            return t;
        }
        if (key < p->data)
            p->lchild = RInsert(p->lchild, key);
        else if (key > p->data)
            p->rchild = RInsert(p->rchild, key);

        p->height = NodeHeight(p);
        if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
            return LLRotation(p);
        else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
            return RRRotation(p);
        else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
            return LRRotation(p);
        else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
            return RLRotation(p);
        return p;
    }

    // Postorder Travarsal
    void Preorder(node *p)
    {
        if (p == NULL)
            return;
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
};
int main()
{
    AVL_Tree t;
    t.root = t.RInsert(t.root, 50);
    t.RInsert(t.root, 60);
    t.RInsert(t.root, 55);
    t.Preorder(t.root);
}