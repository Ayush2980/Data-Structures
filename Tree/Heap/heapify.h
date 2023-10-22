#include <bits/stdc++.h>
using namespace std;
namespace heapifyAlgo
{
    void heapify(int arr[], int n, int i)
    {
        int largest = i;
        int left = 2 * i;      // 2*i+1 if 0->n-1
        int right = 2 * i + 1; // 2*i+2 if 0->n-1

        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

    void heapifyArr(int arr[], int n)
    {
        for (int i = n / 2; i > 0; i--)
            heapify(arr, n, i);
    }
    void heapSort(int arr[], int n)
    {
        int index = n;
        while (index > 1)
        {
            swap(arr[1], arr[index]);
            index--;
            heapify(arr, index, 1);
        }
    }

}
