#include <bits/stdc++.h>
using namespace std;

//Naive:
//Consider every element as smallest bar and find arear with this bar being smallest and keep  track of largest area
//TO find area of rectangle for A[i] being the smallest 
//1.Go to left of it and include all bars whaich have height A[i] or greater siilarly on right
//2.As soon as we find a smaller bar stop 
//Time->O(n2)
int getMaxArea(int A[],int n)
{
    int res=0;
    for(int i=0;i<n;i++)
    {
        int curr=A[i];
        for(int j=i-1;j>=0;j--)
        {
            if(A[j]>=A[i])curr+=A[i];
            else 
                break;
        }
        for(int j=i+1;j<n;j++)
        {
            if(A[j]>=A[i])curr+=A[i];
            else
                break;
        }
        res=max(res,curr);
    }
    return res;
}
//Better:3 traversals + O(n+n) space
//1.Initialize res=0
//2.FInd prev smaller element for every element
//3.find next smaller .....
//4.for every element A[i]
//  curr=A[i]
//  curr+=(i-prev[i]-1)*A[i]
//  curr+=(ns[i]-i-1)*A[i]
//res=max(res,curr)
//COde->

// int getMaxArea(int arr[],int n){
//     int res=0;
//     int ps[n],ns[n];
    
//     stack <int> s;
//     s.push(0);
//     for(int i=0;i<n;i++){
//         while(s.empty()==false && arr[s.top()]>=arr[i])
//             s.pop();
//         int pse=s.empty()?-1:s.top();
//         ps[i]=pse;
//         s.push(i);
//     }
    
//     while(s.empty()==false){
//         s.pop();
//     }
    
//     s.push(n-1);
//     for(int i=n-1;i>0;i--){
//         while(s.empty()==false && arr[s.top()]>=arr[i])
//             s.pop();
//         int nse=s.empty()?n:s.top();
//         ns[i]=nse;
//         s.push(i);
//     }
    
//     for(int i=0;i<n;i++){
//         int curr=arr[i];
//         curr+=(i-ps[i]-1)*arr[i];
//         curr+=(ns[i]-i-1)*arr[i];
//         res=max(res,curr);
//--------------------------------------------------------------------------------
//      vector<int> NSR(long long arr[], int n)
// {
//     stack<int> st;
//     vector<int> right;
//     for(int i=n-1;i>=0;i--)
//     {
//         while(!st.empty() && arr[st.top()]>=arr[i])
//             st.pop();
//         st.empty()?right.push_back(n):right.push_back(st.top());
//         st.push(i);
//     }
//     reverse(right.begin(),right.end());
//     return right;
    
// }
// vector<int> NSL(long long arr[], int n)
// {
//     stack<int> st;
//     vector<int> left;
//     for(int i=0;i<n;i++)
//     {
//         while(!st.empty() && arr[st.top()]>=arr[i])
//             st.pop();
//         st.empty()?left.push_back(-1):left.push_back(st.top());
//         st.push(i);
//     }
//     // reverse(right.begin(),right.end());
//     return left;
    
// }
// long long getMaxArea(long long arr[], int n)
// {
//     // Your code here
//     vector<int> l=NSL(arr,n);
//     vector<int> r=NSR(arr,n);
//     long long mx=0;
//     for(int i=0;i<n;i++)
//     {
//         mx=max(mx,(r[i]-l[i]-1)*arr[i]);
//     }
//     return mx;
// }   }
//     return res;
    
// }



//Optimised:




int main() {
    int A[]={6,2,5,4,1,5,6};
    cout<<getMaxArea(A,7);
    return 0;
}