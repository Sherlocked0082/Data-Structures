#include<bits/stdc++.h>
using namespace std;
//same as array
void insert(stack<int> &s,int temp)
{
    if(s.size()==0 || s.top()<=temp)
    {
        s.push(temp);
        return;
    }

    int value=s.top();
    s.pop();
    insert(s,temp);

    s.push(value);
    return;
}

void sort_recursive(stack<int> &s)
{
    if(s.size()==1)
        return;
    
    int temp=s.top();
    s.pop();
    sort_recursive(s);

    insert(s,temp);
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
    cout<<"Sorted stack\n";
    sort_recursive(s);
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}