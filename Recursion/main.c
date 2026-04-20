#include<stdio.h>

int recursive_fibbonacci(int n)
{
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    
    return recursive_fibbonacci(n-1)+recursive_fibbonacci(n-2);
}

int iterative_fibonacci(int n)
{
    if(n==1)
        return 0;
    if(n==2)
        return 1;
    int t1=0,t2=1;
    for(int i=2;i<n;i++)
    {
        int nxt=t1+t2;
        t1=t2;
        t2=nxt;
    }
    return t2;
}

int main()
{
    int n=40;
    printf("%dth Fibbonacci number using iteration is %d\n",n,iterative_fibonacci(n));
    printf("%dth Fibbonacci number using recurrision is %d",n,recursive_fibbonacci(n));

}