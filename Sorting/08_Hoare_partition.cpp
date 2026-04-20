
#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int h)
{   
    int pivot=arr[l];
    int i=l-1,j=h+1;
    while(true){
        do{
            i++;
        }while(arr[i]<pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i>=j)return j;
        swap(arr[i],arr[j]);
    }
}
 
int main() {
	
    int arr[]={5,3,8,4,2,7,1,10};
	
	int n=sizeof(arr)/sizeof(arr[0]);
	
	partition(arr,0,n-1);
	
	for(int x: arr)
	    cout<<x<<" ";
}




/*
Assumption
consider first eleemt as pivot elemet
i=lo-1  j=hi+1
after every iterations
l to i are smaller than pivot 
j to h are greater than piot

|  <pivot    | unknown |    >pivot   |
lo           i->      <-j            hi 

Hoares partion is not stable
so quick sort is not stable by default

time->O(n)
space-> O(1)
*/