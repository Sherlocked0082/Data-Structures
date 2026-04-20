#include<bits/stdc++.h>
using namespace std;
/*
    Smallest divisor of any number is a prime factor
    For non prime numbers there always exist a prime factor smaller than rootn
*/

int main(){
    int n,cnt=0,sum=0;
    cin>>n;
    //O(root(N))
    vector<int> prime_factors;
    for(int i=2;i*i<=n;i++)
    {
        while(n%i==0)
        {
            prime_factors.push_back(i);
            n/=i;
        }
    }
    //when there is a single prime factor
    if(n>1)
    {
        prime_factors.push_back(n);
    }
    for(prime:prime_factors)
        cout<<prime<<" ";
    return 0;
}