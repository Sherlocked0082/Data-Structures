#include<bits/stdc++.h>
using namespace std;
// if there is a divisor y which is greater than sqrt(n) then 
//there must be its pair less than sqrt(n)     x*y=n
bool isPrime(int n)
{
    if(n==1)return false;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
//but if n is lage then its squareroot is also large so 
//further optimisation
/*by checking n%2=0 we can eliminate even divisior
and by adding a check n%3==0 we can also save many iterations

*/
//this is almost 3 times faster than the efficient implementation
bool isPrime_optimised(int n)
{
    if(n==1)
        return false;
    if(n==2 || n==3)
        return true;
    if(n%2==0 || n%3==0)
        return false;
    for(int i=5;i*i<=n;i+=6)//incremting i by 6 and doing 2 divisibility checks so 3X faster
    {
        if(n%i==0 || n%(i+2)==0)
            return false;
    }
    return true;
}
int main()
{
    cout<<isPrime(1031);
    cout<<isPrime_optimised(1031);
    return 0;
}