#include <bits/stdc++.h>
using namespace std;

namespace BT
{
    class Node
    {
        int n;
        int t;
        Node **child;
        int *keys;
        bool leaf;

    public:
        Node(int t, bool leaf)
        {
            this->t = t;
            this->leaf = leaf;
            this->keys = new int[2 * t - 1];
            this->child = new Node *[2 * t];
            n = 0;
        }
        void insertNonFull(int k)
        {
            int i = n - 1;
            if (this->leaf == true)
            {
                while (i >= 0 && keys[i] > k)
                {
                    keys[i + 1] = keys[i];
                    i--;
                }
                keys[i + 1] = k;
                this->n++;
            }
            else
            {
                while (i >= 0 && keys[i] > k)
                    i--;
                if (child[i + 1]->n == 2 * (this->t) - 1)
                {
                    splitChild(i + 1, this->child[i + 1]);
                    if (keys[i + 1] < k)
                        i++;
                }
                this->child[i]->insertNonFull(k);
            }
        }

        void splitChild(int x, Node *childNode)
        {
            Node *z = new Node(childNode->t, childNode->leaf);
            z->n = t - 1;
            for (int i = 0; i < t - 1; i++)
            {
                z->keys[i] = childNode->keys[i];
            }
            if (childNode->leaf == false)
            {
                for (int i = 0; i < t; i++)
                {
                    z->child[i] = childNode->child[i + t];
                }
            }
            childNode->n = t - 1;
            for (int i = n; i >= x + 1; i--)
            {
                child[i + 1] = child[i];
            }
            child[x + 1] = z;
            for (int j = n - 1; j >= x; j--)
                keys[j + 1] = keys[j];

            keys[x] = childNode->keys[t - 1];

            n = n + 1;
        }
        void traverse()
        {
            int i = 0;
            for (i = 0; i < n; i++)
            {
                if (this->leaf == false)
                    this->child[i]->traverse();
                cout << " " << this->keys[i];
            }
            if (leaf == false)
                this->child[i]->traverse();
        }
        Node *search(int k)
        {
            int i = 0;
            while (i < n && this->keys[i] < k)
                i++;
            if (this->keys[i] == k)
                return this;
            if (this->leaf == false)
                return NULL;
            return this->child[i]->search(k);
        }
        friend class Btree;
    };

    class Btree
    {
        Node *root;
        int t;

    public:
        Btree(int t)
        {
            root = NULL;
            this->t = t;
        }
        void traverse()
        {
            if (root != NULL)
                root->traverse();
        }

        Node *search(int k)
        {
            return (root == NULL) ? NULL : root->search(k);
        }

        void insert(int k)
        {
            if (root == NULL)
            {
                Node *s = new Node(this->t, true);
                s->keys[0] = k;
                s->n = 1;
            }
            else
            {
                if (root->n == 2 * this->t - 1)
                {
                    Node *s = new Node(this->t, false);
                    s->child[0] = root;
                    s->splitChild(0, root);
                    int i = 0;
                    while (s->keys[i] < k)
                        i++;
                    s->child[i]->insertNonFull(k);
                    root = s;
                }
                else
                {
                    root->insertNonFull(k);
                }
            }
        }
    };

}
