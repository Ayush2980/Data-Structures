#include <bits/stdc++.h>
using namespace std;

namespace H
{
    class MaxHeap
    {
    private:
        vector<int> arr;
        int size;

    public:
        MaxHeap()
        {
            arr.push_back(-1);
            size = 0;
        }

        void insert(int val)
        {

            arr.push_back(val);
            size += 1;
            int index = size;

            while (index > 1)
            {
                int parent = index / 2;
                if (arr[parent] < arr[index])
                {
                    swap(arr[parent], arr[index]);
                    index = parent;
                }
                else
                    return;
            }
        }

        void print()
        {
            for (int i = 1; i <= size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        void remove()
        {
            if (size == 0)
            {
                cout << "Nothing to remove!!!" << endl;
                return;
            }
            swap(arr[1], arr[size]);
            size -= 1;
            // top down approach to sort the new root node
            int i = 1;
            while (i < size)
            {
                int left = 2 * i;
                int right = 2 * i + 1;

                if (left < size && arr[i] < arr[left])
                {
                    swap(arr[i], arr[left]);
                    i = left;
                }
                else if (right < size && arr[i] < arr[right])
                {
                    swap(arr[i], arr[right]);
                    i = right;
                }
                else
                {
                    return;
                }
            }
        }
    };
}