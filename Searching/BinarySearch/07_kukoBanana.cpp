//Good thread of quuus
//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/solutions/256729/java-c-python-binary-search/
bool canEat(vector<int> &piles,int speed,int h)
{
    int time=0;
    for(int i=0;i<piles.size();i++)
    {
        if(piles[i]%speed==0)
            time+=piles[i]/speed;
        else
            time+=ceil(piles[i]/speed)+1;
    }
    return (time<=h);
}
int minEatingSpeed(vector<int>& piles, int h) {
    //Monotonic Predicate function:
    //F F F F F F T T T T T T T T T T
    int mx=0;
    for(int i=0;i<piles.size();i++)
        mx=max(mx,piles[i]);
    int lo=1,hi=mx,ans=lo;
    while(lo<hi)
    {
        int mid=lo+(hi-lo)/2;
        if(canEat(piles,mid,h))//Finding the first T
        {
            ans=mid;
            hi=mid;
        }
        else
        {
            lo=mid+1;
        }
    }
    return lo;
}
//variation hard 2a:https://leetcode.com/problems/split-array-largest-sum/
bool canSplit(int mxsum,vector<int> &nums,int k)
{
    int temp=1,sum=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>mxsum)//Edgecase
            return false;
        if(sum+nums[i]<=mxsum)
        {
            sum+=nums[i];
        }
        else
        {
            temp++;
            sum=nums[i];
        }
    }
    return temp<=k;
}
int splitArray(vector<int>& nums, int k) {
    //Monoonic Predicate function
    //F F F F F F F F T T T T T T  T
    int lo=0,hi=1e9;
    while(hi-lo>1)
    {
        int mid=lo+(hi-lo)/2;
        if(canSplit(mid,nums,k))
        {
            hi=mid;
        }
        else
        {
            lo=mid+1;
        }
        // cout<<lo<<" "<<mid<<" "<<hi<<endl;
    }
    if(canSplit(lo,nums,k))
        return lo;
    return hi;
}

//Variation 2:https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/description/

bool isPossible(int mxval,int n,vector<int> &quantities)
{
    int s=0;
    for(int i=0;i<quantities.size();i++)
    {
        if(quantities[i]%mxval==0)
            s+=quantities[i]/mxval;
        else
            s+=ceil(quantities[i]/mxval)+1;
    }
    return (s<=n);
}
int minimizedMaximum(int n, vector<int>& quantities) {
    //Predicate Monotonic function:
    //F F F F  F T T T T  T T
    int mx=0;
    for(int i=0;i<quantities.size();i++)
    {
        mx=max(mx,quantities[i]);
    }
    int lo=1,hi=mx,ans=hi;
    while(lo<hi)
    {
        int mid=lo+(hi-lo)/2;
        if(isPossible(mid,n,quantities))
        {
            ans=mid;
            hi=mid;
        }
        else
        {
            lo=mid+1;
        }
    }
    return ans;
}
//Variation 3:https://leetcode.com/problems/maximum-candies-allocated-to-k-children/solutions/
bool canTake(int c,long long k,vector<int> &candies)
{
    long long s=0;
    for(int i=0;i<candies.size();i++)
    {
        s+=candies[i]/c;
    }
    return (s>=k);
}
int maximumCandies(vector<int>& candies, long long k) {
    //MOnotonic Predicate Function
    //T T T T T T T T F F F F F F F F
    int mx=INT_MIN;
    for(int i=0;i<candies.size();i++)
        mx=max(mx,candies[i]);
    long long lo=1,hi=(long long)mx;
    int ans=0;
    while(lo<=hi)//hi>lo
    {
        long long mid=lo+(hi-lo)/2;
        cout<<hi<<" "<<lo<<" "<<mid<<endl;
        if(canTake(mid,k,candies))
        {
            ans=(int)mid;
            lo=mid+1;//lo=mid
        }
        else
        {
            hi=mid-1;
        }
    }      
    return ans;
}

//VAriation 4:https://leetcode.com/problems/minimum-speed-to-arrive-on-time/description/
bool canReach(int speed,vector<int> &dist,double hour)
{
    double time=0;
    
    for (int i = 0; i < dist.size() - 1; ++i)
        time += ((dist[i] + speed - 1) / speed);

    time += ((double)dist.back()) / speed;
    return time <= hour;

}
int minSpeedOnTime(vector<int>& dist, double hour) {
    //MOnotonic Predicate Function:
    //F F F F F F F T T T T T T T T T 
    int lo=1,hi=1e7,ans=-1;
    while(lo<hi)
    {
        int mid=lo+(hi-lo)/2;
        cout<<hi<<" "<<lo<<" "<<mid<<endl;
        if(canReach(mid,dist,hour))
        {
            ans=mid;
            hi=mid;
        }
        else
        {
            lo=mid+1;
        }
    }
    if(hi!=0 && canReach(hi,dist,hour))
        return hi;
    return ans;
}