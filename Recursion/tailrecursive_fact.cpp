#include<iostream>
using namespace std;

int tailrecursive_fact(int n,int accumalate)
{
    if(n<=1)
        return accumalate;
    return tailrecursive_fact(n-1,accumalate*n);
}
int main()
{
    cout<<tailrecursive_fact(5,1);
}