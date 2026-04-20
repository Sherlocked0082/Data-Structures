#include<bits/stdc++.h>
using namespace std;
#define ll                  long long int


int main(){
    
        ll n;
        cin>>n;
        ll A[n];
        for(int i=0;i<n;i++)
            cin>>A[i];
        vector<pair<int,int>> vp;
        for(int i=0;i<n;i++)
        {
            vp.push_back({A[i],i});
        }
        for(int i=0;i<n;i++)
        {
            cout<<vp[i].first<<" "<<vp[i].second<<" "<<i<<endl;
        }        
    return 0;
}