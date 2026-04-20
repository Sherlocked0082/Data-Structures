#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;
/*
Default logic in c++ sort is ascending order
But we can pass custom behaviour using comparator function
comaparator function says 
"IF U WANT TO SWAP RETURN FALSE"
trick to remeber->return that what u want 
*/

// bool cmp(pair<int,int> a,pair<int,int> b)
// {
//     if(a.first!=b.first){
//         if(a.first>b.first) return false;//we have to do this so 
//         return true;
//     }
//     else{
//         if(a.second<b.second) return false;//we have to do this so 
//         return true;
//     }
// }

//trick->
bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.first!=b.first){
        return a.first<b.first;//here we need this so return this
    }
    else{
        return a.second>b.second;
    }
}
//funct to sort in descnding order
// bool cmp(int a,int b)
// {
//     return a>b;
// }
int main() 
{ 
    int n;
    cin>>n;
    vector<pair<int,int> > a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<n;i++)
    {
        cout<<a[i].first<<" "<<a[i].second<<endl;
    }
	
}
