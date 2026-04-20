int Solution::removeElement(vector<int> &A, int B) {
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
