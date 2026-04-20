#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v={2,3,4,5,6};
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    //Range based loops
    //1.vector
    for(int value : v)//the vector values are copied to the variable value so even if 
    //u make some change it willnot effect
    {
        cout<<value<<" ";
    }
    cout<<endl;
    //to pass byrefrence
    for(int &value : v)
    {
        cout<<value<<" ";
    }
    cout<<endl;
    //2.pairs
    vector<pair<int,int>> v_p={{1,2},{2,3}};
    for(pair<int,int> &value :v_p)
    {
        cout<<value.first<<" "<<value.second<<endl;
    }
    cout<<endl;
//-------------------------------------------------------------
//Auto keyword->It automatically determines the data type
    for(auto &value :v_p)
    {
        cout<<value.first<<" "<<value.second<<endl;
    }


    return 0;
}