#include<iostream>
#include<queue>
using namespace std;
//given an element x and k print k closer elements of x
//VIMP-> Custom somparator using structures for priority queue

/*Naive
time->O(nk)
space->O(n)
*/
void printKclosest_naive(int A[],int n,int k,int x)
{
    bool visited[n]={false};
    for(int i=0;i<k;i++)
    {
        int min_diff=INT_MAX;
        int min_diff_indx;
        for(int j=0;j<n;j++)
        {
            if(visited[j]==false && abs(A[j]-x)<=min_diff)
            {
                min_diff=abs(A[j]-x);
                min_diff_indx=j;
            }
        }
        cout<<A[min_diff_indx]<<" ";
        visited[min_diff_indx]=true;
    }
}

//optimised using maxheap
//time->O(nlogk)
void printKcloasest_optimised(int A[],int n,int k,int x)
{
    priority_queue<pair<int,int> >pq;
    for(int i=0;i<k;i++)//O(klogk)
    {
        pq.push({abs(A[i]-x),i});
    }
    for(int i=k;i<n;i++)//O((n-k)*logk)
    {
        int diff=abs(A[i]-x);
        if(pq.top().first>diff)//always remember to pop useless value
        {
            pq.pop();
            pq.push({diff,i});
        }
    }
    while(pq.empty()==false)//O(klogk)
    {
        cout<<A[pq.top().second]<<" ";
        pq.pop();
    }

}

void printkclosest_different(int A[],int n,int k,int x)
{
    priority_queue<pair<int,int> >pq;
    for(int i=0;i<n;i++)
    {
        pq.push({abs(x-A[i]),A[i]});
        if(pq.size()>k){
            pq.pop();
        }
    }
    while(pq.empty()==false)
    {
        cout<<pq.top().second<<" ";
        pq.pop();
    }
}
int main() 
{ 
    int arr[] = { 10,30,5,40,38,80,70 };

	int size = sizeof(arr) / sizeof(arr[0]);

	int x=35; int k = 3;

	printKclosest_naive(arr,size,k,x);
    cout<<"\nUsing max heap\n";
    printKcloasest_optimised(arr,size,k,x);
    cout<<"\n";
    printkclosest_different(arr,size,k,x);
    return 0;
}
//-----------------------------------------------------------------------------------------
//GFG constraints variations
/*
If X is present in the array, then it need not be considered.
If there are two elements with the same difference with X, the greater element is given priority.
If sufficient elements are not present on the right side then take elements from left and vice versa.
*/

//For above constraints use custom comparator for priority queue using structures***

    struct compare{
    bool operator ()(pair<int,int>a,pair<int,int>b){
         if(a.first!=b.first){
             return a.first<b.first;
         }
         return a.second>b.second;
     }
    };

    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==x)
                continue;
            pq.push({abs(arr[i]-x),arr[i]});
            if(pq.size()>k)
                pq.pop();
        }
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }