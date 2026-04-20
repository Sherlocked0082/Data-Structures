int removeDuplicates(vector<int> &A) {
    int idx=0;
    for(int i=1;i<A.size();i++)
    {
        if(A[i]!=A[idx])
        {
            idx++;
            A[idx]=A[i];
        }
    }
    return idx+1;
}
