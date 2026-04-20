
//time->O(n2)  space=O(1) can be optimised using prioityqueue check it
static bool cmp(Job a,Job b)
    {
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,cmp);
        
        int slots[n]={0};//slots for booking the Job 
        int profit=0,jobsdone=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=min(n,arr[i].dead-1);j>=0;j--)//take min cause dead may be greater than n which will lead to overflow
            {
                if(slots[j]==0)//find the earliest slot
                {
                    slots[j]=1;
                    profit+=arr[i].profit;
                    jobsdone++;
                    break;
                }
            }
        }
        
        return {jobsdone,profit};
    } 