#include <bits/stdc++.h>
using namespace std;

namespace avl
{
    class Node
    {
    public:
        int data;
        Node *left, *right;
        int height;
        Node(int k)
        {
            this->data = k;
            this->left = NULL;
            this->right = NULL;
            height = 1;
        }
    };

    class AVL
    {
        Node *root = NULL;
        int getHeight(Node *node)
        {
            if (node == NULL)
                return 0;
            return node->height;
        }
        int BF(Node * node)
        {
            return getHeight(node->left)- getHeight(node->right);
        }
        Node *LR(Node *pivot)
        {
            Node *newPivot = pivot->right;
            Node *adjust = newPivot->left;
            newPivot->left = pivot;
            pivot->right = adjust;
            newPivot->height = 1 + max(getHeight(newPivot->left), getHeight(newPivot->right));
            pivot->height = 1 + max(getHeight(pivot->left), getHeight(pivot->right));
            return newPivot;
        }

        Node *RR(Node *pivot)
        {
            Node *newPivot = pivot->left;
            Node *adjust = newPivot->right;
            newPivot->right = pivot;
            pivot->left = adjust;
            newPivot->height = 1 + max(getHeight(newPivot->left), getHeight(newPivot->right));
            pivot->height = 1 + max(getHeight(pivot->left), getHeight(pivot->right));
            return newPivot;
        }
    public:
        Node *insert(Node *node, int key)
        {
            if (node == NULL)
                return new Node(key);
            if (key > node->data)
            {
                node->right = insert(node->right, key);
            }
            else if (key < node->data)
            {
                node->left = insert(node->left, key);
            }

            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
            int bf = BF(node);
            if (bf < -1 && key > node->right->data)
            {
                return LR(node);
            }
            if (bf > 1 && key < node->left->data)
            {
                return RR(node);
            }
            if (bf < -1 && key < node->right->data)
            {
                node->right = RR(node->right);
                return LR(node);
            }
            if (bf > 1 && key > node->left->data)
            {
                node->left = LR(node->left);
                return RR(node);
            }

            return node;
        }


        void levelOrder()
        {
            queue<Node *> q;
            q.push(root);
            q.push(NULL);
            while (!q.empty())
            {
                Node *temp = q.front();
                q.pop();
                if (temp == NULL)
                {
                    cout << endl;
                    if (!q.empty())
                        q.push(NULL);
                }
                else
                {
                    cout << temp->data << " ";
                    if (temp->left)
                        q.push(temp->left);
                    if (temp->right)
                        q.push(temp->right);
                }
            }
        }
    };
}