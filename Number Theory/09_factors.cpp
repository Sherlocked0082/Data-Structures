#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,cnt=0,sum=0;
    cin>>n;
    //O(root(N))
    for(int i=0;i*i<n;i++)
    {
        if(n%i==0)
        {
            cnt++;
            sum+=i;
            cout<<i<<" "<<n/i<<endl;
            if(n/i!=i)
            {
                sum+=n/i;
                cnt++;
            }
        }
    }
    /*
        MOre optimised ALgo PnC
        X=p1n1 p2n2 …
        All possible subsets of above divisors covers all the divisors

        No of divisors=(n1+1)(n2+1)

        Sum of Divisors=(1+p1+p12+p13....)(1+p2+p22+p23+p24)...
        Apply GP here
    
    
    */



    return 0;
}