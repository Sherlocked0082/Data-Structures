#include<bits/stdc++.h>
using namespace std;

//Variation 2: Unlimited buy sell
int StockBuySell3(vector<int>& prices) {
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
int f(int idx,int buy,vector<int> &prices,int cap)
{
    int n=prices.size();
    if(idx==n || cap==0)
        return 0;
    
    long long profit=0;
    if(buy)
    {
        profit=max(-prices[idx]+f(idx+1,0,prices,cap),f(idx+1,1,prices,cap));
    }
    else
    {
        profit=max(+prices[idx]+f(idx+1,1,prices,cap-1),f(idx+1,0,prices,cap));
    }
    return profit;
}
//M4:Tabulation
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<vector<vector<int>>> dp(n+2, vector<vector<int>>(2,vector<int> (3,0)));

    //Here no need to write base case as we have initialized with 0 only 
    //Base Cases:
    // for(int idx=0;idx<n;idx++)
    // {
    //     for(int buy=0;buy<=1;buy++)
    //     {
    //         dp[idx][buy][0]=0;
    //     }
    // }

    // for(int buy=0;buy<=1;buy++)
    // {
    //     for(int cap=0;cap<=2;cap++)
    //     {
    //         dp[n][buy][cap]=0;
    //     }
    // }

    for(int idx=n-1;idx>=0;idx--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            for(int cap=1;cap<=2;cap++)
            {
                if(buy)
                {
                    dp[idx][buy][cap]=max(-prices[idx]+dp[idx+1][0][cap],dp[idx+1][1][cap]);
                }
                else
                {
                    dp[idx][buy][cap]=max(+prices[idx]+dp[idx+1][1][cap-1],dp[idx+1][0][cap]);
                }           
            }
        }
    }
    return dp[0][1][2];
}
int main(){
    int n;
	cin>>n;
	vector<int> prices(n);
	for(int i=0;i<n;i++)
        cin>>prices[i];
    // cout<<StockBuySell3(prices)<<endl;
    cout<<f(0,1,prices,2)<<endl;
    return 0;
}

