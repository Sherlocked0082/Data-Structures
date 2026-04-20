bool findPair(int A[],int lo,int hi,int sum)
    {
        while(lo<hi)
        {
            if(A[lo]+A[hi]==sum)
                return true;
            else if(A[lo]+A[hi]>sum)
                hi--;
            else
                lo++;
        }
        return false;
    }
    bool find3Numbers(int A[], int n, int X)
    {
        sort(A,A+n);
        for(int i=0;i<n-1;i++)
        {
            int sum=X-A[i];
            if(findPair(A,i+1,n-1,sum))
                return true;
        }
        return false;
    }

    //-----------------------------------------------------------------
//Using Hashing:
bool find3Numbers(int A[], int n, int X)
    {
        unordered_set<int> s;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int y=X-(A[i]+A[j]);
            if(s.find(y)!=s.end())
                return true;
            s.insert(A[j]);
            
        }
    }
    return false;
    }