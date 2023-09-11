#ifndef LIST_H
#define LIST_H
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Node{
    public :
    T data;
    Node<T>* prev = NULL;
};

template<typename T>
class Stack{

    public :
    Node<T> * up = NULL;
    int size =0;
    T top(){
        if(!empty()) return up->data;
        else{
            cout << "Empty stack" <<endl;
            return up->data;
        }
    };
    T pop(){
        if(!empty()){
            T val = up->data;
            up = up->prev;
            size--;
            return val;
        }
        else{
            cout <<"Empty Stack" <<endl;
            return up->data;
        }
    };
    void push(T val){
        Node<T> * ptr = new Node<T>;
        ptr->data = val;
        ptr->prev = up;
        up = ptr;  
        size++;
    };
    bool empty(){
        if(size) return 0;
        return 1; 
    };
};

#endif
