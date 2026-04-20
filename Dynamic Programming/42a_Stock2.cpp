#include<bits/stdc++.h>
using namespace std;

//Variation 2: Unlimited buy sell
int StockBuySell2(vector<int>& prices) {
    int n=prices.size();
    int selling_date=0,buying_date=0,profit=0;
    
    for(int i=1;i<n;i++)
    {
        if(prices[i]>=prices[i-1])
            selling_date++;
        else
        {
            profit+=prices[selling_date]-prices[buying_date];
            selling_date=i;
            buying_date=i;
        }
    }
    profit+=prices[selling_date]-prices[buying_date];//for the last upstroke(VIMP)
    
    return profit;
}

//Recursion version
//Time->pow(2,n)
int f(int idx,int buy,vector<int> &prices)
{
    int n=prices.size();
    if(idx==n)
        return 0;
    
    long long profit=0;
    if(buy)
    {
        profit=max(-prices[idx]+f(idx+1,0,prices),f(idx+1,1,prices));
    }
    else
    {
        profit=max(+prices[idx]+f(idx+1,1,prices),f(idx+1,0,prices));
    }
    return profit;
}

//M4:Tabulation
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<vector<int>> dp(n+1,vector<int> (2,0));
    dp[n][0]=0,dp[n][1]=0;
    for(int idx=n-1;idx>=0;idx--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            int profit=0;
            if(buy)
            {
                dp[idx][buy]=max(-prices[idx]+dp[idx+1][0],dp[idx+1][1]);
            }
            else
            {
                dp[idx][buy]=max(prices[idx]+dp[idx+1][1],dp[idx+1][0]);
            }       
        }
    }
    return dp[0][1];
}

//Space Optimization:









int main(){
    int n;
	cin>>n;
	vector<int> prices(n);
	for(int i=0;i<n;i++)
        cin>>prices[i];
    cout<<StockBuySell2(prices)<<endl;
    cout<<f(0,1,prices)<<endl;
    return 0;
}

