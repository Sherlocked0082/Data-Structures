#include <bits/stdc++.h>
using namespace std;


//sorting + SLiding Window
int distributechocolate(int A[],int n,int m)
{
    if(m>n)return -1;
    sort(A,A+n);
    int ans=A[m-1]-A[0];
    for(int i=1;i+m-1<n;i++)
    {
        ans=min(ans,A[m+i-1]-A[i]);
    }
    return ans;
}
 
int main() {
	

}