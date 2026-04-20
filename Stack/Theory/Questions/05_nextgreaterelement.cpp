#include <bits/stdc++.h>
using namespace std;
//18 12 13 14 11 16
//This prints in reverse order
void next_greater_element(int A[],int n)
{
    stack<int> s;
    s.push(A[n-1]);
    cout<<-1<<" ";
    for(int i=n-2;i>=0;i--)
    {
        while(s.empty()==false && s.top()<=A[i])
        {
            s.pop();
        }
        int prev_great=s.empty()?-1:s.top();
        cout<<prev_great<<" "; 
        s.push(A[i]);
    }
}

//Next Greater Elements2 : variation ->Array is circular :)
// vector<int> nextGreaterElements(vector<int>& nums) {
//     vector<int> ans;
//     stack<int> st;
//     int n=nums.size();
//     for(int i=n-1;i>=0;i--) just put all the elements in the stack 
//         st.push(nums[i]);
//     for(int i=n-1;i>=0;i--)
//     {
//         while(!st.empty() && st.top()<=nums[i])
//             st.pop();
//         st.empty()?ans.push_back(-1):ans.push_back(st.top());
//         st.push(nums[i]);
//     }
//     reverse(ans.begin(),ans.end());
//     return ans;
// }


int main() {
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }    
    next_greater_element(A,n);

	return 0;
}