#include<bits/stdc++.h>
using namespace std;

/*GIven n strings ,print unique strings in any order with their frequency
n<=10^5
s<=100
but if s<=100000 then we cant use these
*/
//Iterating using auto keyword
void print(unordered_map<string,int> &m)
{
    cout<<m.size()<<endl;
    for(auto &pr : m){
        cout<<pr.first<<" "<<pr.second<<"\n";
    }//accessing and inserting->log(n)
}
int main()
{
    unordered_map<string,int> m;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int count=0;
        string s;
        cin>>s;
        //m[s]=m[s]+1;
        m[s]++;//standard method to calculate frequency
    }
    print(m);
    return 0;
}
/*i/p
8
abc
def
abc
ghi
jkl
ghi
ghi
abc
*/
