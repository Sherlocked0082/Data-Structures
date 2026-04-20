// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int A[], int n, int k) {
        sort(A,A+n);
        int ans=A[n-1]-A[0];
        for(int i=1;i<n;i++)//i starts from 1
        {
            if(A[i]>=k)
            {
                int mn=min(A[i]-k,A[0]+k);//    
                int mx=max(A[n-1]-k,A[i-1]+k);//i-1 as we dont want the last elelemnt
                ans=min(ans,mx-mn);
            }
            
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends