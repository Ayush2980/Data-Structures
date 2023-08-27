#ifndef LIST_H
#define LIST_H
#include <bits/stdc++.h>
#include "../Double LinkedLIst/ErrorHandler.h"
using namespace std;

class Node{
    public : 
    int data;
    Node * next;
    Node * prev;
};

class DCLL{
    private: 
    Node * head = nullptr;
    Node * tail = nullptr;
    int length = 0;
    Node * findPtr(int index);

    public: 
    void push_back(int data);
    void add_forth(int data);
    void pop_forth();
    void pop_back();
    void PrintList();
    void ReversePrint();
    int size();
    int at(int index);
    void insert(int data  , int index);
    void pop_at_n( int index);
};

Node * DCLL::findPtr(int index){
    Node * ptr = head;
    int i = 0;
    while(i != index){
        ptr = ptr->next;
        i++;
    }
    return ptr;
}

int DCLL::size(){
    return length;
}

void DCLL::push_back(int data){
    Node * curr = new Node;
    curr->data = data;
    if(length){
        tail->next = curr;
        curr->prev = tail;
        curr->next = head;
        head->prev = curr;
        tail = curr;
    }
    else{
        head = curr;
        tail = curr;
        curr->next = head;
        curr->prev = tail;
    }
    length++;
}

void DCLL::PrintList(){
    Node * ptr = head;
    if(length){
        while(ptr->next!= head){
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << ptr->data << " ";
        cout << endl;
    }
    else cout << "Empty List" << endl;
}

void DCLL::add_forth(int data){
    Node * curr = new Node;
    curr->data = data;
    if(length){
        curr->next = head;
        head->prev = curr;
        head = curr;
        head->prev = tail;
        tail->next = head;
        length++;
    }
    else{
        push_back(data);
    }
}

void DCLL::insert(int data ,  int index){
    if(index == 0) add_forth(data);
    else if(index == length-1) push_back(data);
    else{
        Node * curr = new Node;
        Node * ptr = findPtr(index);
        curr->data = data;
        ptr->prev->next = curr;
        curr->prev = ptr->prev;
        curr->next = ptr;
        ptr->prev = curr;
        length++;
    }

}

void DCLL::pop_back(){
    if(length == 0){
        cout << "You cant Remove from an empty list !!!" << endl;
    }
    else if(length != 1){
        Node * ptr = tail;
        head->prev = tail->prev;
        tail->prev->next = head;
        tail = tail->prev;
        free(ptr);
        length--;
    }
    else{
        head = nullptr;
        tail = nullptr;
        length--;
    }
}

void DCLL::pop_forth(){
    if(length == 0 || length == 1)pop_back();
    else{
        Node * ptr = head; 
        head->next->prev = tail;
        tail->next = head->next;
        head = head->next;
        free(ptr);
        length--;
    }
}

void DCLL::pop_at_n(int index){
    if(index == 0) pop_forth();
    else if(index == length-1) pop_back();
    else{
        Node * ptr = findPtr(index);
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
        length--;
    }
}

int DCLL::at(int index){
    if(index < length || length >= 0){
        Node * ptr = findPtr(index);
        return ptr->data;
    }
    return INT_MIN;
}

void DCLL::ReversePrint(){
    Node * ptr = tail;
    while(ptr->prev != tail){
        cout << ptr->data << " ";
        ptr=  ptr->prev;
    }
    cout << ptr->data << endl;
}

#endif