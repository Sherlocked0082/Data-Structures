#include<bits/stdc++.h>
using namespace std;

void solve(stack<int> &s,int k)
{
    if(k==1)//base condition
    {
        s.pop();
        return;
    }
    //--------------------------------------------
    //hypothesis
    int temp=s.top();//storing top element
    s.pop();
    solve(s,k-1);

    //--------------------------------------------
    s.push(temp);//indution
    return;
}
stack<int> delete_middle(stack<int> &s,int size)
{
    if(s.size()==0)
        return s;
    int k=size/2 + 1;
    solve(s,k);
    return s;
}
int main()
{
    int n;
    cin>>n;
    stack<int> s;
    stack <int> ans;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s.push(x);
    }
    ans=delete_middle(s,n);
    while(!ans.empty())
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }
    return 0;
}