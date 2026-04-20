void Solution::sortColors(vector<int> &A) {

    int n=A.size();
    int lo=0,hi=n-1,i=0;
    while(i<=hi)
    {
        if(A[i]==2)//2
            swap(A[i],A[hi--]);
        else if(A[i]==0)//0
            swap(A[i++],A[lo++]);
        else//1
            i++;
    }
}