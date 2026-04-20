#include<bits/stdc++.h>
using namespace std;

void Print(int n)
{
    if(n==1)
    {
        cout<<n<<" ";
        return;
    }
    Print(n-1);
    cout<<n<<" ";
}
int main()
{
    Print(8);

    return 0;
}