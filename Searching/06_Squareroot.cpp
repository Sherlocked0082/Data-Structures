#include<iostream>
using namespace std;

int sqrt_bs(int x)
{
    int lo=0,hi=x,ans=-1;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        int mid_sq=mid*mid; 

        if(mid_sq==x)
            return mid;
        else if(mid_sq>x)
            hi=mid-1;
        else
        {
            lo=mid+1;
            ans=mid;//here we want floor so we store this as a answer
        }
    }
    return ans;
}
int main()
{
    cout<<sqrt_bs(5);
    return 0;
}