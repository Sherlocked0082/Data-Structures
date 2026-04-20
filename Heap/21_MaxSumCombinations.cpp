// //VIMP Question
//GOOD QUUSS
// Given two equally sized 1-D arrays A, B containing N integers each.
// A sum combination is made by adding one element from array A and another element of array B.
// Return the maximum C valid sum combinations from all the possible sum combinations.

// https://www.interviewbit.com/problems/maximum-sum-combinations/

//Naive: 
//Go through all possible combinations and select top k maxSum
//will give  Memory Limit Exceeded
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    
    priority_queue<int> pq;
    for(int i=0;i<A.size();i++)
    {
        for(int j=0;j<B.size();j++)
        {
            pq.push(A[i]+B[j]);
        }
    }
    int cnt=0;
    vector<int> ans;
    while(!pq.empty() && cnt<C)
    {
        ans.push_back(pq.top());
        pq.pop();
        cnt++;
    }
    return ans;

}

//Optimised:**
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    
    priority_queue<pair<int,pair<int,int>>> pq;//->{sum,{i,j}}
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int n=A.size();
    
    set<pair<int,int>> s;
    
    pq.push({A[n-1]+B[n-1],{n-1,n-1}});//insert-> {sum,{idx1,idx2}}
    s.insert({n-1,n-1});//hashing-> TO keep track which index is inserted in Heap
    
    vector<int> ans;
    int cnt=0;
    while(!pq.empty() && cnt<C)
    {
        auto it=pq.top();
        int sum=it.first;
        int i=it.second.first;
        int j=it.second.second;
        
        ans.push_back(sum);
        pq.pop();
        
        //insert A[i-1],B[i] into Heap --> B4 inserting into heap check if A[i-1],B[j] are already present in heap or not 
        if(s.find({i-1,j})==s.end())
        {
            pq.push({A[i-1]+B[j],{i-1,j}});
            s.insert({i-1,j});
        }
        
        //insert A[i],B[i-1] into Heap--> B4 inserting into heap check if A[i],B[j-1] are already present in heap or not 
        if(s.find({i,j-1})==s.end())
        {
            pq.push({A[i]+B[j-1],{i,j-1}});
            s.insert({i,j-1});
        }
        
        cnt++;
    }
    
    return ans;

}