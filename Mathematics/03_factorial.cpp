#include<bits/stdc++.h>
using namespace std;

int recursive_factorial(int n)
{
    if(n==0)
        return 1;
    
    return n*recursive_factorial(n-1);
}

int iterative_factorial(int n)
{
    int ans=1;
    for(int i=1;i<=n;i++)
        ans*=i;
    
    return ans;
}
int main()
{
    cout<<factorial(3);

    return 0;
}

#include<stdio.h>

int main()
{
    int n=30;
    printf("Factorial of %d using recursion is %d\n",n,recursive_factorial(n));
    printf("Factorial of %d using iteration is %d\n",n,iterative_factorial(n));
}