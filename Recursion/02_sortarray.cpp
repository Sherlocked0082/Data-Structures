#include<bits/stdc++.h>
using namespace std;

void insert(vector<int> &v,int temp)
{
    if(v.size()==0 || v[v.size()-1]<=temp)//base condition
    {
        v.push_back(temp);
        return;
    }
    //-----------------------------------------------------------
    int value=v[v.size()-1];//hypothesis
    v.pop_back();
    insert(v,temp);
    //-----------------------------------------------------------
    v.push_back(value);//induction
    return;
}

void sort_recursive(vector<int> &v)
{
    if(v.size()==1)//base condition f there is nly one element
        return;
    //-----------------------------------------------------------
    int temp=v[v.size()-1];//stored the last element(Hypothesis)
    v.pop_back();
    sort_recursive(v);
    //-----------------------------------------------------------
    insert(v,temp);//induction step
}
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort_recursive(v);
    cout<<"sorted array "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}