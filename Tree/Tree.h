#include <bits/stdc++.h>
using namespace std;
namespace T{
    class Node
    {
    public:
        int data;
        Node *left, *right;

        Node(int d)
        {
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
    };

    class Tree
    {
        Node * root = NULL;
        public:
        Tree();
        void levelOrder();
        void inorder();
        void preorder();
        void postorder();
    };
    Node *buildTree(Node *root)
    {
        int k;
        cin >> k;
        root = new Node(k);
        if (k == -1)
            return NULL;
        cout << "Enter the left child of " << root->data << endl;
        root->left = buildTree(root->left);
        cout << "Enter the right child of " << root->data << endl;
        root->right = buildTree(root->right);

        return root;
    }

    Tree::Tree(){
        root = buildTree(root);
    }

    void Tree::levelOrder(){
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
    void func_inorder(Node * root){
        if(root == NULL) return;
        func_inorder(root->left);
        cout << root->data << " ";
        func_inorder(root->right);
    }
    void func_preorder(Node * root){
        if(root == NULL) return;
        cout << root->data << " ";
        func_preorder(root->left);
        func_preorder(root->right);
    }
    void func_postorder(Node * root){
        if(root == NULL) return;
        func_postorder(root->left);
        func_postorder(root->right);
        cout << root->data << " ";
    }

    void Tree::postorder(){
        func_postorder(root);
    }
    void Tree::inorder(){
        func_inorder(root);
    }
    void Tree::preorder(){
        func_preorder(root);
    }


}


//to include in other files simply write #include "relative_path"
//using namespace T

