#include<bits/stdc++.h>
using namespace std;


bool isPalidrome(int n)
{
    int rev=0;
    int temp=n;
    while(temp!=0)
    {
        int ld=temp%10;
        rev=rev*10+ld;
        temp/=10;
    }
    return(rev==n);
}

int main()
{
    cout<<isPalidrome(98789);

    return 0;
}