#ifndef LIST_H
#define LIST_H
#include <bits/stdc++.h>
using namespace std;



class Node{
    public : 
    int data;
    Node * next;
};

class LinkedList{
    private : 
    Node *  head = nullptr;
    Node *  last = nullptr;
    int length = 0;


    public : 
    void push_back(int data);
    void add_forth(int data);
    void pop_forth();
    void pop_back();
    void PrintList();
    int size();
    int at(int index);
    void insert(int data  , int index);
    void pop_at_n( int index);
};
void LinkedList::PrintList(){
    Node * ptr = head;
    while(ptr != nullptr){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void LinkedList::push_back(int data){
    Node * temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    if(head != nullptr){
        last->next = temp;
        last = temp;
    }
    else{
        head = temp;
        last = temp;
    }
    length++;
}

void LinkedList::add_forth(int data){
    Node * temp = new Node;
    temp->data = data;
    temp->next = head;
    head = temp;
    length++;
}

void LinkedList::pop_forth(){
    Node * temp = head;
    head = temp->next;
    length--;
    delete(temp);
}


void LinkedList::pop_back(){
    Node * temp = head;
    while(temp->next != last){
        temp = temp->next;
    }
    temp->next = NULL;
    delete(last);
    last = temp;
    length--;
}

int LinkedList::size(){
    return length;
}

int LinkedList::at(int index){
    int i =0;
    if(i <= length-1){
        Node * ptr = head;
        while(i!=index){
            ptr = ptr->next;
            i++;
        }
        return ptr->data;
    }
    return INT_MIN;
}

void LinkedList::insert(int data , int index){
    Node * curr = new Node;
    curr->data = data;
    Node * temp = head , * prev_temp;
    int i =0;
    if(index == length) push_back(data);
    else if(index == 0) add_forth(data);
    else if(index < length){
        while(i!=index){
            if(i == index-1){
                prev_temp = temp;
            }
            i++;
            temp = temp->next;
        }
        prev_temp->next = curr;
        curr->next = temp; 
        length++;
    }
    else{
        throw OutOfBounds();
    }
}

void LinkedList::pop_at_n(int index){
    Node * temp = head , * prev_temp , *curr;
    int i =0;
    if(index == length-1) pop_back();
    else if(index == 0) pop_forth();
    else if(index < length){
        while(i!=index){
            if(i == index-1) prev_temp = temp;
            i++;
            temp = temp->next;
        }
        prev_temp->next = curr->next;
        delete(temp);
        length--;
    }
    else{
        throw OutOfBounds();
    }



}

#endif