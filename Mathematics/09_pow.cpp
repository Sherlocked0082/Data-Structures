#include<bits/stdc++.h>
using namespace std;

int power(int x,int n)
{
    int res=1;
    for(int i=1;i<=n;i++)
    {
        res=res*x;
    }
    return res;
}
//optiised

    /*
        3¹⁰ =3⁸ * 3²        10=1010
        3¹⁹ =3¹⁶ * 3² * 3¹  19=10011
    */

    int power(int x,int n)
    {
        int res=1;
        while(n>0)
        {
            if(n%2!=0)
            {
                res=res*x;
            }
            x=x*x;
            n=n/2;
        }
        return res;
    }
int main()
{
    cout<<power(2,9);
    cout<<power_op(2,9);
    return 0;
}