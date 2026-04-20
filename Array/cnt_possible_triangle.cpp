#include <bits/stdc++.h>
using namespace std;
 
void CountTriangles(vector<int> A)
{
 
    int n = A.size();
    sort(A.begin(), A.end());
    int count = 0;
 
    for (int i = n - 1; i >= 1; i--) {
        int l = 0, r = i - 1;
        while (l < r) {
            if (A[l] + A[r] > A[i]) {//   5   6    7   8  9  12
 
                // If it is possible with a[l], a[r]
                // and a[i] then it is also possible
                // with a[l+1]..a[r-1], a[r] and a[i]
                count += r - l;
 
                // checking for more possible solutions
                r--;
            }
            else
 
                // if not possible check for
                // higher values of arr[l]
                l++;
        }
    }
    cout << "No of possible solutions: " << count;
}
int main()
{
 
    vector<int> A = {1,1,1 };
 
    CountTriangles(A);
}
//--------------------------------------------------------------
//InterviewBit
int Solution::nTriang(vector<int> &A) {
    sort(A.begin(),A.end());
    int n=A.size(),cnt=0,num=1e9+7;
    for(int i=n-1;i>=1;i--)
    {
        int lo=0,hi=i-1;
        while(lo<hi)
        {
            if(A[lo]+A[hi] > A[i])
            {
                cnt=(cnt+(hi-lo)%num)%num;
                hi--;
            }
            else
            {
                lo++;
            }
        }
        
    }
    return cnt%num;
}
