#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b)          for(int i=a;i<b;i++)
#define Fo(i,k,n)           for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll                  long long int
#define pb                  push_back
#define mp                  make_pair
#define deb(x)              cout << #x << "=" << x << endl
#define all(x)              x.begin(), x.end()
#define clr(x)              memset(x, 0, sizeof(x))
#define sortall(x)          sort(all(x))
#define PI                  3.1415926535897932384626



void solve(int t) {
    int n;
    cin>>n;
    vector<int> X(n),Y(n);
    rep(i,0,n){
        cin>>X[i];
    }
    rep(i,0,n){
        cin>>Y[i];
    }
    
    map<int,set<pair<int,int>>> mp1;    
    map<int,set<pair<int,int>>> mp2;    

    for(int i=0;i<n;i++)
    {
        mp1[Y[i]-X[i]].insert({X[i],Y[i]});
        mp2[Y[i]+X[i]].insert({X[i],Y[i]});
    }

    for(auto x:mp1)
    {
        set<pair<int,int>> s=x.second;
        cout<<x.first<<" -> "
        for(auto y:s)
        {
            cout<<"{ "<<y.first<<" , "<<y.second<<" }  ";
        }
        // cout<<x.first<<" -> "<<x.second.first<<" , "<<x.second.second<<endl;
    }




}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    rep(i,1,t+1) solve(i);
    return 0;
}