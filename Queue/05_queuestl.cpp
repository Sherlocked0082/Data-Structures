#include<bits/stdc++.h>
using namespace std;
//all are implememnted in o(1)

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    // cout<<q.front()<<" "<<q.back()<<"\n";
    // q.pop();
    // cout<<q.front()<<" "<<q.back()<<"\n";
    // q.pop();
    // cout<<q.front()<<" "<<q.back()<<"\n";
    while(q.empty()==false)
    {
        cout<<q.front()<<" "<<q.back()<<"\n";
        q.pop();
    }
    return 0;
}