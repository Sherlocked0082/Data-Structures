#include<bits/stdc++.h>
#define ll long long 
#define lld long double
#define deb(x) cout << #x << " = " << x << endl
using namespace std;

void solve(int A[],vector<vector<int>> &ans,int k,int n,vector<int> temp)
{
    if(k==n)
    {
        ans.push_back(temp);
        return;
    }
    solve(A,ans,k+1,n,temp);
    
    temp.push_back(A[k]);
    solve(A,ans,k+1,n,temp);
    return;
}

int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    int k=0;
    vector<vector<int> > ans;
    vector<int> temp;
    solve(A,ans,k,n,temp);
    sort(ans.begin(), ans.end());
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }       
    return 0;
}
