#include<iostream>
using namespace std;

//maximum subarray sum
int Kadane_Algo(int A[],int n)
{
    int sum=0;
    int maxium=INT_MIN;
    //carry subarray as long it gives positive sum
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        maximum=max(maximum,sum);
        if(sum<0)
            sum=0;

    }
    return maximum;
}

//brute force -> O(n3)

int main()
{
    
}