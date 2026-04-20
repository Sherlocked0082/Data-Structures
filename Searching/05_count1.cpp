#include<iostream>
using namespace std;

//just need to do one check A[mid-1]==A[mid] ??
int count_ones(int A[],int n,int x)//x=1
{
    int lo=0,hi=n-1;
    while(lo<hi)
    {
        int mid=(lo+hi)/2;
        if(A[mid]==x)
        {
            if(mid==0 || A[mid-1]!=A[mid])
                return (n-mid);//
            else//if same thenmove in left subarray
                hi=mid-1;
        }
        // else if(A[mid]>x)
        // {
        //     hi=mid-1;
        // }
        else//A[mid]<x
            lo=mid+1;

    }
    return -1;
}
int main()
{




    return 0;
}