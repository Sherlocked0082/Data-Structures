/*
 Subset Sum Equals to Target 
//Thought Process:
1.Express{f(idx,target)} and Write BAse case
2.Explore possibilities of that idx
    a[idx] taken ,notten
3.return T/F

State 
A={2,1,3,4,5}
  n--------->
  f(n,target)=>till nth elemtn is there any subseq with sum as target

Tabulation Thought process:
a.write base cases
b.Form nested loops
    idx->(1,n-1)
    target->(1-target)
*/



//Tabulation:
bool isSubsetSum(vector<int>arr, int sum){
    // code here 
    int n=arr.size();
    vector<vector<bool>> dp(n,vector<bool>(sum+1,0));
    
    // dp[i][j]->target,sum
    for(int i=0;i<n;i++)
        dp[i][0]=true;
    dp[0][arr[0]]=true;
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            bool notTake=dp[i-1][j];
            bool take=false;
            if(arr[i]<=j)
                take=dp[i-1][j-arr[i]];
            dp[i][j]=take|notTake;
        }
    }
    return dp[n-1][sum];
    
    
}