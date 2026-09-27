#include <bits/stdc++.h>
using namespace std;

class heap
{
  public:
    int arr[100];
    int size;

    heap()
    {
      arr[0] = -1;
      size = 0;
    }

    void insert(int val)
    {
      size++;
      int index = size;
      arr[index] = val;

      while(index > 1)
      {
        int parent = index/2;
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

    void deleteFromHeap()
    {
        if(size == 0)
        {
            cout << "Nothing to delete" << " ";
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;

        while(i <= size)
        {
            int leftindex = 2*i;
            int rightindex = 2*i + 1;
            int largest = i;

            if(leftindex <= size && arr[leftindex] > arr[largest])
            {
                largest = leftindex;
            }

            if(rightindex <= size && arr[rightindex] > arr[largest])
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

    void print()
    {
      for(int i = 1; i <= size; i++)
      {
        cout << arr[i] << " ";
      }cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
  int leftindex = 2*i;
  int rightindex = 2*i + 1;
  int largest = i;

  if(leftindex <= n && arr[leftindex] > arr[largest])
  {
    largest = leftindex;
  }
  if(rightindex <= n && arr[rightindex]> arr[rightindex])
  {
    largest = rightindex;
  }
  if(largest != i)
  {
    swap(arr[i], arr[largest]);
    heapify(arr,n,largest);
  }
}

int main()
{
  heap h;
  h.insert(60);
  h.insert(50);
  h.insert(40);
  h.insert(30);
  h.insert(20);
  h.insert(55);
  h.insert(70);
  h.print();
  h.deleteFromHeap();
  h.print();

  int ar[7] = {-1, 60, 50, 55, 30, 20, 40};
  int n = 6;
  for(int i = n/2; i > 0; i--)
  {
    heapify(ar, n, i);
  }

  cout<< " Printing the arr now" << endl;
  for(int i = 1; i <= n; i++){
    cout<< ar[i] << " ";
  }cout<<endl;
}