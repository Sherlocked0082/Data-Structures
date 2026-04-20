#include<bits/stdc++.h>
using namespace std;

struct Queue
{
    int *arr;
    int front,size,cap;//here we are not maintaining rear as we can get rear by the formula
    //rear=(front+size-1)%cap
    Queue(int c)
    {
        arr=new int[cap];
        cap=c;
        front=0;
        size=0;
    }
     bool isFull()
    {
        return(size==cap);
    }
    bool isEmpty()
    {
        return(size==0);
    }
    int getrear()
    {
        if(isEmpty())
            return -1;
        else
            return(front +size-1)%cap;
    }
    void enque(int x)//o(1)
    {
        if(isFull())
            return;
        int rear=getrear();
        rear=(rear+1)%cap;
        arr[rear]=x;
        size++;
    }
    void deque()//o(1)
    {
        if(isEmpty())
            return;
        front=(front+1)%cap;
        size--;
    }
    
};

int main()
{


    return 0;
}