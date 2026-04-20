//begin with index 1 then 2 then 4 then 16 keep doing while current 
// ellemnt is smaller than x
//log(position)
//THis algorithm is commonly known as unbounded Binary Search
int search_infinite(int A[],int n)
{
    if(A[0]==x)
        return 0;
    int i=1;
    while(A[i]<x)
        i*=2;
    if(A[i]==x)
        return i;

    return binarysearch(A,x,i/2+1,i);
}