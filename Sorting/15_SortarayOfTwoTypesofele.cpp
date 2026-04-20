#include <bits/stdc++.h>
using namespace std;
/*
Naive




efficient solution:






*/

 
int main() {
	

}

/*
Forms:
1.Segregate positive negative



2.Segregate even odd
*/
void segregateEvenOdd(int arr[], int size)
{
    /* Initialize left and right indexes */
    int left = 0, right = size-1;
    while (left < right)
    {
        /* Increment left index while we see 0 at left */
        while (arr[left] % 2 == 0 && left < right)
            left++;
 
        /* Decrement right index while we see 1 at right */
        while (arr[right] % 2 == 1 && left < right)
            right--;
 
        if (left < right)
        {
            /* Swap arr[left] and arr[right]*/
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }
}




// 3.Sort binary array
 void binSort(int A[], int n)
    {
        int lo=0,hi=n-1;
        while(lo<hi)
        {
            while(A[lo]==0 && lo<hi)
                lo++;
            while(A[hi]==1 && lo<hi)
                hi--;
            if(lo<hi)
            {
                swap(A[lo],A[hi]);
                lo++;
                hi--;
            }
        }
    }


4.moveZeroes
 void moveZeroes(vector<int>& nums) {
        int idx=0,i=0;
        while(i<nums.size())
        {
            if(nums[i]!=0)
            {
                swap(nums[idx++],nums[i]);
            }
            i++;
        }
    }








*/