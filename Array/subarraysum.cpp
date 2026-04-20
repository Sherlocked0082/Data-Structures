vector<int> subarraySum(int A[], int n, long long s)
{
    // Your code here
    int l=0,r=0;
    long long sum=A[0];
    while(l<n && r<n)
    {
        if(sum==s)
        {
            return {l+1,r+1};
        }
        if(sum<s)
            sum+=A[++r];
        else
            sum-=A[l++];
    }
    return {-1};
}