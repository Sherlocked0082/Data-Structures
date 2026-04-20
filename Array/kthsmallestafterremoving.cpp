/*
Given an array arr[] of size ‘n’ and a positive integer k. 
Consider series of natural numbers and remove arr[0], arr[1], 
arr[2], …, arr[n-1] from it. Now the task is to find k-th smallest number in the remaining set of natural numbers.
*/
int kThSmallest_afterremoving(int A[],int n,int k)
{
    for(int i=0;i<n;i++)
    {
        if(A[i]<=k)
            k++;
        else //assume array is sorted
            break;
    }
    return k;
}
