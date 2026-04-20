#include <bits/stdc++.h>
using namespace std;
//18 12 13 14 11 16
void previous_greater_element(int A[],int n)
{
    stack<int> s;//will hold the indexes
    s.push(0);
    cout<<"-1 ";
    int ans;
    for(int i=1;i<n;i++){//check this again
        while(s.empty()==false && A[s.top()] <=A[i])
        {
            s.pop();
        }
        ans=s.empty()?-1:A[s.top()];
        cout<<ans<<" ";
        s.push(i);
    }
    cout<<endl;
}

void previous_greater_element2(int A[],int n)
{
    stack<int> s;
    s.push(A[0]);
    cout<<"-1 ";
    int ans;
    for(int i=1;i<n;i++)
    {
        while(s.empty()==false && s.top()<A[i])
        {
            s.pop();      
        }
        ans=s.empty()?-1:s.top();
        cout<<ans<<" ";
        s.push(A[i]);
    }
}
int main() {
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }    
    previous_greater_element(A,n);
    previous_greater_element2(A,n);
	return 0;
}