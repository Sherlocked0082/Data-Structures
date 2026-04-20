int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int idx=0,n=A.size(),cnt=1;
    
    for(int i=1;i<n;i++)
    {
        if(A[i]==A[i-1])
        {
            cnt++;
            
        }
        else
            cnt=1;
        if(cnt<=2)
        {
            idx++;
            A[idx]=A[i];
        }
    }

    return idx+1;
}
