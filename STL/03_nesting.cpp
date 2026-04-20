#include<bits/stdc++.h>
using namespace std;

void printvec(vector<pair<int,int>> &v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
}
void printarrvec(vector<int> &v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}
int main()
{
    //vector of pairs
    vector<pair<int,int> > v={{1,2},{2,3},{3,4}};
    printvec(v);

    //--------------------------------------------
    //array of vector
    vector<int> av[10];//10 vectors are creted
    for(int i=0;i<10;i++)
    {
        int n;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            av[i].push_back(x);
        }
    }
    for(int i=0;i<10;i++)
    {
        printarrvec(av[i]);
    }
    //-----------------------------------------------
    //vector of vector
    vector<vector<int>> vv;
    for(int i=0;i<10;i++)
    {
        int n;
        cin>>n;
        vector<int> temp;
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        vv.push_back(temp);
        //---------------------------------
        
        for(int i=0;i<vv.size();i++)
        {
            printarrvec(vv[i]);
        }
    }
    return 0;
}
