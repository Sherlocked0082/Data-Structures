//NAIVE O(n2)
//TLE
long long int inversionCount(long long A[], long long n)
{
    long long int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(A[i]>A[j])
                cnt++;
        }
    }
    
    
    return cnt;
}

//--------------------------------------------------------------------------------
//Optimisation using mergesort:
/*
implement a logic in merge process of mergesort

*/