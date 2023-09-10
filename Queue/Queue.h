#ifndef LIST_H
#define LIST_H
template <typename T>
class Queue
{
    T *data;
    int front = -1;
    int rear = 0;
    int size = 0;
    int capacity = 1;

public:
    Queue(int s)
    {
        data = new T[s];
        capacity = s;
    }
    void Enqueue(T val)
    {
        if (size == capacity)
        {
            cout << "Queue Full" << endl;
            return;
        }
        else
        {
            data[rear] = val;
            rear = (rear + 1) % capacity;
            size++;
        }
        if (front == -1)
        {
            front = 0;
        }
    };
    void Dequeue()
    {
        if (size == 0)
        {
            cout << "Empty Queue" << endl;
            return;
        }
        else
        {
            front = (front + 1) % capacity;
            size--;
        }
    };
    void printIt()
    {
        if (size == 0)
        {
            cout << "Emptgy Queue" << endl;
            return;
        }
        for (int i = front, j = 0; j < size; j++, i = (i + 1) % capacity)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    };
    T Front(){
        return data[front];
    }
};
#endif