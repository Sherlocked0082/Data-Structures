#include<bits/stdc++.h>
using namespace std;

void insert_at_end(stack<int> &s,int element)
{
    if(s.size()==0)
    {
        s.push(element);
        return;
    }

    int temp=s.top();
    s.pop();
    insert_at_end(s,element);

    s.push(temp);
    return;
}
void reverse_stack(stack<int> &s)
{
    if(s.size()==1)
        return;
    
    int element=s.top();
    s.pop();
    reverse_stack(s);
    insert_at_end(s,element);
    return;
}
int main()
{
    int n;
    cin>>n;
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s.push(x);
    }
    reverse_stack(s);
    while(!s.empty())
    {
       cout<<s.top()<<" ";
       s.pop();
    }
    return 0;
}