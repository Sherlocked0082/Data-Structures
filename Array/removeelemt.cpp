int Solution::removeElement(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int cnt=0,n=A.size();
    int i=0,j=0;
    while(i<n)
    {
        if(A[i]!=B)
        {
            A[j++]=A[i];
            cnt++;
        }
        i++;
    }
    return cnt;

}
