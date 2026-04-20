#include<bits/stdc++.h>
using namespace std;

int countdigits(int x)
{
    int res=0;
    while(x>0)
    {
        x/=10;
        res++;
    }
    return res;
}
int main()
{
    cout<<countdigits(198701);

    return 0;
}