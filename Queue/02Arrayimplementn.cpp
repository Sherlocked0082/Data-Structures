#include<bits/stdc++.h>
using namespace std;

struct Queue
{
    int size,cap;
    int *arr;
    Queue(int c)
    {
        cap=c;
        size=0;
        arr=new int[cap];
    }

    bool isFull()
    {
        return(size==cap);
    }
    bool isEmpty()
    {
        return(size==0);
    }
    void enque(int x)//o(1)
    {
        if(isFull())
            return;
        arr[size]=x;
        size++;
    }
    void deque()//o(n)as we need 1st element at index 0
    {
        if(isEmpty())
            return;
        for(int i=0;i<size-1;i++)
        {
            arr[i]=arr[i-1];
        }
        size--;
    }
};

int main()
{


    return 0;
}