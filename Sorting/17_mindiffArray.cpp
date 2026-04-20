//Naive 
//consider every pair and get min
int minDiff(int A[],int n)
{
    int res=INT_MAX;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            res=min(res,abs(A[i]-A[j]));
        }
    }
    return res;
}

// optimised
int minDiff(int A[],int n)
{
    sort(A,A+n);
    int diff=A[1]-A[0];
    for(int i=1;i<n;i++)
    {
        diff=min(diff,A[i]-A[i-1]);
    }
    return diff;
}
