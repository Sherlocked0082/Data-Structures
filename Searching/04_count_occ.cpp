#include<iostream>
using namespace std;


int firstocc(int A[],int n,int x)
{
    int lo=0,hi=n-1;
    while(lo<hi)
    {
        int mid=(lo+hi)/2;
        if(A[mid]==x)
        {
            if(mid==0 || A[mid-1]!=A[mid])
                return mid;
            else//if same thenmove in left subarray
                hi=mid-1;
        }
        else if(A[mid]>x)
        {
            hi=mid-1;
        }
        else
            lo=mid+1;

    }
    return -1;
}

int last_occ(int A[],int n,int x)
{
    int lo=0,hi=n-1;
    while(lo<hi)
    {
        int mid=(lo+hi)/2;
        if(A[mid]==x)
        {
            if(mid==n-1 || A[mid+1]!=A[mid])
                return mid;
            else//if same thenmove in left subarray
                lo=mid+1;
        }
        else if(A[mid]>x)
        {
            hi=mid-1;
        }
        else
            lo=mid+1;

    }
    return -1;
    
}

int count_occ(int A[],int n,int x)
{
    int first=firstocc(A,n,x);
    if(first==-1)
        return 0;
    return (last_occ(A,n,x) - first + 1);
}    
int main()
{

    int A[10]={1,2,3,4,5,5,5,5,6,7};
    cout<<count_occ(A,10,5);


    return 0;
}