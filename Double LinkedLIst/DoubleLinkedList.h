#ifndef LIST_H
#define LIST_H
#include <bits/stdc++.h>
using namespace std;

class Node{
    public : 
    int data;
    Node * next;
    Node * prev;
};

class DoubleLinkedList{
    private:
    Node * head = nullptr;
    Node * last = nullptr;
    int length = 0;

    public : 
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

void DoubleLinkedList::PrintList(){
    Node * ptr = head;
    while(ptr!= nullptr){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}


void DoubleLinkedList::ReversePrint(){
    Node * ptr = last;
    while(ptr != nullptr){
        cout << ptr->data << " ";
        ptr = ptr->prev;
    }
    cout << endl;
}

void DoubleLinkedList::push_back(int data){
    Node * temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    if(head == nullptr){
        temp->prev = nullptr;
        head = temp;
        last = temp;
    }
    else{
        last->next = temp;
        temp->prev = last;
        last = temp;
    }
    length++;
}

void DoubleLinkedList::pop_back(){
    Node * ptr = last;
    if(length == 1){
        head = nullptr;
        free(last);
        last = nullptr;
    }
    else{
        ptr = ptr->prev;
        ptr->next = nullptr;
        free(last);
        last = ptr;
    }
    length--;
}

int DoubleLinkedList::size(){
    return length;
}

void DoubleLinkedList::add_forth(int data){ 
    Node * temp = new Node;
    temp->data = data;
    temp->prev = nullptr;
    if(length == 0){
        temp->next = nullptr;
        head = temp;
        last = temp;
    }
    else {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    length++;
}


void DoubleLinkedList::pop_forth(){
    Node * ptr =  head;
    if(length == 1){
        head = nullptr;
        free(last);
        last = nullptr;
    }
    else{
        ptr = ptr->next;
        free(head);
        ptr->prev = nullptr;
        head = ptr;
    }
    length--;
}
int DoubleLinkedList::at(int index){
    if(index > (length-1)/2){
        Node * ptr = last;
        int i =0;
        while(i!=length-1-index){
            ptr = ptr->prev;
            i++;
        }
        return ptr->data;
    }
    else{
        Node * ptr = head;
        int i =0;
        while(i != index){
            ptr = ptr->next;
            i++;
        }
        return ptr->data;
    }
}

void DoubleLinkedList::insert(int data , int index){ 
    if(index == 0) add_forth(data);
    else if(index == length) push_back(data);
    else{
        Node * curr = new Node , *temp = head;
        curr->data = data;
        int i =0;
        while(i != index){
            temp = temp->next;
            i++;
        }
        curr->prev = temp->prev;
        curr->next = temp;
        temp->prev->next = curr;
        temp->prev = curr;
    }
}

void DoubleLinkedList::pop_at_n(int index){
    if(index == 0)pop_forth();
    else if(index == length-1)pop_back();
    else {
        if(index > (length-1)/2){
            Node * ptr = last;
            int i =0;
            while(i!=length-1-index){
                ptr = ptr->prev;
                i++;
            }
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            length--;
        }
        else{
            Node * ptr = head;
            int i =0;
            while(i != index){
                ptr = ptr->next;
                i++;
            }
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            length--;
        }
    }
}




#endif