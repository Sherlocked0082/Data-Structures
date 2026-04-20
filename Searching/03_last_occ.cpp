#include<iostream>
using namespace std;


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
int main()
{




    return 0;
}