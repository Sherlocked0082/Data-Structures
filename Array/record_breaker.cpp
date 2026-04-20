//Kicstart
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

typedef pair<ll, ll>    pii;
typedef vector<ll>      vi;
typedef vector<pii>     vpii;
typedef vector<vi>      vvi;
const ll maxn = 1e5+6 ;
const ll MOD = 1e9 + 7  ;
const int MAXTprime=1e6;

void solve(int test){
    ll n,cnt=0;
    cin>>n;
    ll A[n];
    rep(i,0,n)cin>>A[i];

    ll maxtillnow=A[0];
    rep(i,0,n)
    {
        if(A[i]>maxtillnow)
        {
            if(i==n-1)
            {
                cout<<A[i]<<" ";
                cnt++;
            }
            else if(A[i+1]<A[i])
            {
                cout<<A[i]<<" ";
                cnt++;
            }

        }   
        maxtillnow=max(maxtillnow,A[i]);
    }

    cout<<"Case #"<<test<<": "<<cnt; //Google Kickstart    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    rep(i,1,t+1) solve(i);
    return 0;
}

//1 sec -> 10^8 operations