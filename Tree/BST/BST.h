#include <bits/stdc++.h>
using namespace std;

namespace B
{
    class Node
    {
    public:
        int data;
        Node *right;
        Node *left;
        Node(int k)
        {
            this->data = k;
            this->right = NULL;
            this->left = NULL;
        }
    };

    class BST
    {
    private:
        Node *Insertnode(Node *root, int data)
        {
            if (root == NULL)
                return new Node(data);
            if (data > root->data)
                root->right = Insertnode(root->right, data);
            else
                root->left = Insertnode(root->left, data);
            return root;
        }

        int pre(Node *root, int key)
        {
            if (!root)
                return -1;
            if (root->data == key)
            {
                Node *temp = root->left;
                while (temp->right)
                {
                    temp = temp->right;
                }
                return temp->data;
            }
            if (key > root->data)
            {
                return pre(root->right, key);
            }
            return pre(root->left, key);
        }
        int succ(Node *root, int key)
        {
            if (!root)
                return -1;
            if (root->data == key)
            {
                Node *temp = root->right;
                while (temp->left)
                {
                    temp = temp->left;
                }
                return temp->data;
            }
            if (key > root->data)
            {
                return succ(root->right, key);
            }
            return succ(root->left, key);
        }
        bool search(Node *node, int k)
        {
            // Space complexity more in recursive manner
            //  if(node == NULL) return 0;
            //  if(node->data == k) return 1;
            //  else if(k > node->data) return search(node->right , k);
            //  else return search(node->left , k);

            // Less space complexity :: iterative manner
            while (node != NULL)
            {
                if (node->data == k)
                    return 1;
                if (k > node->data)
                    node = node->right;
                else
                    node = node->left;
            }
            return 0;
        }
        Node * deleteNode(Node* root , int key){
            if(root == NULL) return root;
            if(root->data == key){
                //0 Child
                if(root->left == NULL && root->right == NULL){
                    delete root;
                    return NULL;
                }
                //1 left child
                else if(root->left != NULL && root->right == NULL){
                    Node * temp  = root->left;
                    delete root;
                    return temp;
                }
                //1 right Child 
                else if(root->left == NULL && root->right != NULL){
                    Node * temp = root->right;
                    delete root;
                    return temp;
                }
                //2 child 
                Node * temp = root->left;
                while(temp->right){
                    temp = temp->right;
                }
                root->data = temp->data;
                root->right = deleteNode(root->right , temp->data);
                return root;


            }
            if(key > root->data){
                root->right = deleteNode(root->right , key);
                return root;
            }
            else{
                root->left = deleteNode(root->left , key);
                return root;
            }
        }

    public:
        Node *root = NULL;
        void create()
        {
            int data;
            cout << "Enter Your BST" <<endl;
            cin >> data;
            while (data != -1)
            {
                root = Insertnode(root, data);
                cin >> data;
            }
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

        bool find(int key){
            return search(root , root->data);
        }

        int findPre(int key){
            return pre(root,key);
        }

        int findSucc(int key){
            return succ(root, key);
        }
        void remove(int key){
            deleteNode(root , key);
        }
    };
}
