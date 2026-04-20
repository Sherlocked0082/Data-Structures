//Sliding window :)
long long findMinDiff(vector<long long> a, long long n, long long m){
    sort(a.begin(),a.end());
    long long ans=a[m-1]-a[0];
    for(int i=1;i<n-m+1;i++)
    {
        long long t=a[m+i-1]-a[i];
        ans=min(ans,t);
    }
    return ans;
}   