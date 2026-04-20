//You need to find the number of subarrays in A having sum less than B. We may assume that there is no overflow.
int Solution::solve(vector<int> &A, int k) {
    int n=A.size();
    int start=0,end=0,cnt=0,sum=A[0];
    while(start<n && end<n)
    {
        if(sum<k)
        {
            end++;
            if(end>=start)
                cnt+=end-start;
            
            if(end<n)
                sum+=A[end];
        }
        else
        {
            sum-=A[start++];
        }
    }
    return cnt;
}
