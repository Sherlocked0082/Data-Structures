#include<bits/stdc++.h>
using namespace std;
//naive solution is to calcuate factorial fo a given number and then to count the trailing zeros
typedef long long ll;
//But this will cause overflow for slightly higher values of n ie for n =20
ll countzeroes_naive(ll n)
{
    ll fact=1;
    for(ll i=2;i<=n;i++)
    {
        fact=fact*i;
    }
    ll res=0;
    while(fact%10==0)
    {
        res++;
        fact/=10;
    }
    return res;
}
//JEE TYPE METHOD
/*
count no of 5's and no of 2's 
ie they will will club and form 10
but no of 5's are always less than no of 2's
so we need to count only number of 5's
the 5's comes after a period of 5 
but for nubers like 25 5 comes 2 times in its factorization
so the accurate formula for it is
------------------------------------------------------------------------
Formula->
--------------------------------------------------------------------------
TRAILING ZERO COUNT=floor(n/5)+floor(n/25)+floor(n/125)+floor(n/625)+........
--------------------------------------------------------------------------
time->theta(logn)
*/
int countTrailingzeroes(int n)
{
    int res=0;
    for(int i=5;i<=n;i=i*5)
    {
        res=res+n/i;
    }
    return res;
}

int main()
{
    cout<<countzeroes_naive(10)<<" \n";
    cout<<countTrailingzeroes(251);
    return 0;
}