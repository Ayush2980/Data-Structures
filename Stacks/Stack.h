#include <bits/stdc++.h>
using namespace std;

class Node{
    public : 
    int data;
    Node * prev;
};

class LinkedList{
    private : 
    Node *  top = nullptr;
    int length = 0;


    public : 
    void push_back(int data);
    void pop_back();
    void PrintList();
    int size();
};


void LinkedList:: push_back(int data){
    Node * ptr = new Node;
    ptr->data = data;
    if(length){
        ptr->prev = top;
        top = ptr;
    }
    else{
        top = ptr;
        ptr->prev = nullptr;
    }
    length++;
}


void LinkedList::PrintList(){
    Node * ptr = top;
    if(length){
        while(ptr->prev != nullptr){
            cout << ptr->data << " ";
            ptr = ptr->prev;
        }
        cout << ptr->data << endl;
    }
    else cout << "Empty Stack  !!" << endl;
}

void LinkedList::pop_back(){
    Node * ptr = top->prev;
    if(length){
        free(top);
        top = ptr;
        length--;
    }
    else{
        cout << "Empty Stack" <<endl;
    }
}

int main(){
    LinkedList a;
    a.push_back(0);
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.pop_back();
    a.pop_back();
    a.pop_back();
    a.pop_back();
    a.PrintList();

    return 0;
}

