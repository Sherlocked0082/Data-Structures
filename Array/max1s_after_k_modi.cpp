//Problemset link 
//In the solution section of ..
// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/solutions/4384405/java-c-python-sliding-window/
//Pause
// https://leetcode.com/problems/longest-nice-subarray/solutions/2534644/sliding-window-bit-manipulation-easy-understanding-c/
//------------------------------------------------------------------------------------
int Solution::solve(vector<int> &A, int k) {
    int cnt=0,j=0,ans=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]==0)//aquire till valid
            cnt++;
        while(cnt>k)//release till invalid
        {
            if(A[j]==0)
                cnt--;
            j++;
        }
        int length=i-j+1;
        ans=max(ans,length);//keep track of max len
    }
    return ans;
}


//---------------------------------------------------------------------------------
//Variation 1: Max confusion in exam:
// https://leetcode.com/problems/maximize-the-confusion-of-an-exam/
//Solution 1:
int maxflip(string s,int k,char key)//key->true/false (which can be fliped)
{
    int left=0,ans=0,cnt=0;
    for(int right=0;left<s.size() && right<s.size();right++)
    {
        if(s[right]==key)
            cnt++;
        while(cnt>k)
        {
            if(s[left]==key)
                cnt--;
            left++;
        }
        ans=max(ans,right-left+1);
    }
    return ans;
}
int maxConsecutiveAnswers(string answerKey, int k) {
    return max(maxflip(answerKey,k,'T'),maxflip(answerKey,k,'F'));
}

//Solution 2: Using 1 Pass
int maxConsecutiveAnswers(string s, int k) {
    int left=0,ans=0,cntT=0,cntF=0;
    for(int right=0;left<s.size() && right<s.size();right++)
    {
        if(s[right]=='T')
            cntT++;
        else
            cntF++;
        
        while(min(cntT,cntF)>k)
        {
            if(s[left]=='T')
                cntT--;
            else
                cntF--;
            left++;
        }
        ans=max(ans,right-left+1);
    }
    return ans;
}

//----------------------------------------
//Variation 4 Codeforcezs 
//Find lebgth of minimum string such that it contains 1 2 3 exactly 1
//https://codeforces.com/contest/1354/problem/B
void solve(int t) {
    string s;
    cin>>s;
    int left=0,ans=INT_MAX;
    unordered_map<char,int> mp;
    for(int right=0;left<s.size() && right<s.size();right++)
    {
        mp[s[right]]++;
        while(mp[s[left]]>1)
        {
            mp[s[left]]--;
            left++;
        }
        if(mp.size()==3)
            ans=min(ans,right-left+1);
    }
    if(ans==INT_MAX)
        cout<<0<<endl;
    else
        cout<<ans<<endl;
    
}


//--------------------------------------------------------------------
//Calculate inside while loop
// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        //atleast k times
        //A[j...i] -> k times
        //j.....i....l -> l-i+1 times
        //l=n-1
        int mx=0,cnt=0,n=nums.size(),j=0;
        long long ans=0;
        for(auto it:nums)mx=max(mx,it);

        for(int i=0;i<nums.size();i++)
        {
            //aquire till k
            if(nums[i]==mx)cnt++;
            
            //release 
            while(cnt>=k)
            {
                if(cnt==k)
                    ans+=(long long)n-i;
                if(nums[j]==mx)
                    cnt--;
                j++;
            }

        }
        return ans;
    }
};

//---------------------------------------------------------------------------
//SLiding window with bitwise operations 
