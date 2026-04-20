#include <bits/stdc++.h>
using namespace std;
//18 12 13 14 11 16
//pushing the index of the element
vector<int> previous_greater_element(int A[],int n)
{
    stack<int> s;//will hold the indexes
    vector<int> v;
    s.push(n-1);
    v.push_back(-1);
    //cout<<"-1 ";
    int ans;
    for(int i=n-2;i>=0;i--){
        while(s.empty()==false && A[s.top()] <=A[i])
        {
            s.pop();
        }
        ans=s.empty()?-1:A[s.top()];
        //cout<<ans<<" ";
        v.push_back(i);
    }
    reverse(v.begin(),v.end());
    return v;
    //cout<<endl;
}
//pushing the element itself
vector<int> previous_greater_element2(int A[],int n)
{
    stack<int> s;
    vector<int> v;
    s.push(A[n-1]);
    v.push_back(-1);
    //cout<<"-1 ";
    int ans;
    for(int i=n-2;i>=0;i--)
    {
        while(s.empty()==false && s.top()<A[i])
        {
            s.pop();      
        }st
        ans=s.empty()?-1:s.top();
        //cout<<ans<<" ";
        v.push_back(A[i]);
    }
    reverse(v.begin(),v.end());
    return v;
}
int main() {
    int n;
    cin>>n;
    int A[n];
    vector<int> ans;
    vector<int> ans1;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }    
    ans=previous_greater_element(A,n);
    ans1=previous_greater_element2(A,n);
	for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}

