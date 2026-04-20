#include<bits/stdc++.h>
using namespace std;

//naive  O(min(a,b))
int gcd_naive(int a,int b)
{
    int res=min(a,b);
    while(res>0)
    {
        if(a%res==0 && b%res==0)
        {
            break;
        }
        res--;
    }
    return res;
}
//euclid algo
int gcd_euclid(int a,int b)
{
    while(a!=b)
    {
        if(a>b)
            a=a-b;
        else
            b=b-a;
    }
    return a;
}
//recursive and optimised euclidian
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}//log(min(a,b))
int lcm(int a,int b)
{
    return(a*b)/gcd(a,b);
}//O(log(min(a,b)))
int main()
{
    cout<<gcd(4,6);
    cout<<lcm(4,6);
    return 0;
}