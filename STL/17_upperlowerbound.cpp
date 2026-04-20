#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
/*
For these functions to work in logn time the aray 
or vector must be sorted.if not sorted they will work in o(n)
*/
int main() 
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    sort(A,A+n);
    for(int i=0;i<n;i++)
    {
        cout<<A[i];
    }
}