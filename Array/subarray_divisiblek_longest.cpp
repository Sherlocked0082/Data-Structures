int longSubarrWthSumDivByK(int A[], int n, int k)
{
	unordered_map<int,int> mp;
	mp[0]=-1;
	int sum=0,rem,ans=0;
	for(int i=0;i<n;i++)
	{
		sum+=A[i];
		int rem=sum%k;
		if(rem<0)
			rem+=k;
		if(mp.find(rem)!=mp.end())
			ans=max(ans,i-mp[rem]);
		else
			mp[rem]=i;
	}
	return ans;
}