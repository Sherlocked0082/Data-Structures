#include <bits/stdc++.h>
using namespace std;
//Naive solution
//6 2 5 4 1 5 6
int getMaxarea(int A[],int n)
{
    int res=0;
    for(int i=0;i<n;i++)
    {
        int curr=A[i];
        for(int j=i-1;j>=0;j--)
        {
            if(A[j]>=A[i])
                curr+=A[i];
            else
                break;
        }
        for(int j=i+1;j<n;j++)
        {
            if(A[j]>=A[i])
                curr+=A[i];
            else
                break;
        }
        res=max(res,curr);
    }
    return res;
}
int main() {
    int n,ans;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }    
    ans=getMaxarea(A,n);
	cout<<ans;
    return 0;
}