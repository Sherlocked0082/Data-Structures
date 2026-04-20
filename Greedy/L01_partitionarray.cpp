class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum=0,n=arr.size();
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        if((sum)%3!=0)
            return false;
        int tar=sum/3,cnt=0;
        sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum==tar)
            {
                sum=0;
                cnt++;
            }
        }
        return cnt>=3;
    }
};