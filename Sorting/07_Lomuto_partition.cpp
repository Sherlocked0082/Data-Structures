
#include <bits/stdc++.h>
using namespace std;

int Partition(int A[],int lo,int hi)
{
    int pivot=A[hi];//standard assumption
    int i=lo-1;

    for(int j=lo;j<=hi-1;j++)//A[h] is pivot so go till h-1
    {
        if(A[j]<pivot)
        {
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[hi]);
    return i+1;
}

int main() {
	
    int arr[]={10,80,30,90,40,50,70};
	
	int n=sizeof(arr)/sizeof(arr[0]);
	
	Partition(arr,0,n-1);
	
	for(int x: arr)
	    cout<<x<<" ";
}





/*
intitial assumption:
pivot is always last element
Traverse form lo to h-1
while traversing we ensure elements from
ENSURE
0 to i -> smaller than pivot
i+1 to j-1 -> greater than pivot

IDEA:if u see smaller elements simply increent the window of
smaller element by 1 and do swapping
Atlast swap the pivot with i+1ht element
as i+1 th element will be greater
and position of pivot is i+1

int standard Lomuto pivot is last elemetn

if pivot is not the last element
then swap the pivot elememt with last element
swap(A[p],A[h]);

time->O(n)
space-> O(1)
*/