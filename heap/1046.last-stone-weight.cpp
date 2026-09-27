#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

// @lc code=start
class Solution {
public:

    void heapify(vector<int>& arr, int n, int i)
    {
    int leftindex = 2*i + 1;
    int rightindex = 2*i + 2;
    int largest = i;

    if(leftindex < n && arr[leftindex] > arr[largest])
    {
        largest = leftindex;
    }
    if(rightindex < n && arr[rightindex]> arr[largest])
    {
        largest = rightindex;
    }
    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr,n,largest);
    }
    }

    void insert(int val, int& size , vector<int>& arr)
    {

      int index = size;
      arr[index] = val;
      size++;
      while(index > 0)
      {
        int parent = (index-1)/2;
        if(arr[parent] < arr[index])
        {
          swap(arr[parent], arr[index]);
          index = parent;
        }
        else
        {
          return;
        }
      }
    }
    void deleteFromHeap(vector<int>& arr, int& size)
    {
        if(size == 0)
        {
            cout << "Nothing to delete" << " ";
            return;
        }

        arr[0] = arr[size-1];
        size--;

        int i = 0;

        while(i < size)
        {
            int leftindex = 2*i + 1;
            int rightindex = 2*i + 2;
            int largest = i;

            if(leftindex < size && arr[leftindex] > arr[largest])
            {
                largest = leftindex;
            }

            if(rightindex < size && arr[rightindex] > arr[largest])
            {
                largest = rightindex;
            }

            if(largest != i)
            {
                swap(arr[i], arr[largest]);
                i = largest;
            }
            else
            {
                return;
            }
        }
    }

    int lastStoneWeight(vector<int>& stones)
    {
        int n = stones.size();
        for(int i = n/2-1; i >= 0; i--)
        {
            heapify(stones,n,i);
        }
        int size = n;

        while(size > 1)
        {
            int largest = stones[0];
            deleteFromHeap(stones, size);

            int secondLargest = stones[0];
            deleteFromHeap(stones, size);

            int difference = largest - secondLargest;

            if(difference != 0)
            {
                insert(difference, size, stones);
            }
        }

        if(size == 0)
            return 0;

        return stones[0];
    }
};
// @lc code=end

