#include<bits/stdc++.h>
using namespace std;
/*
Maps=values+keys
Map->stores key value pairs
1.in normal maps keys are stored in sorted order(internally is implemented by red black trees)
2.There are unique keys in maps we cant insert duplicate string
3.in  map we cant do (it+k) instead we need to do it++(as maps are not continous)
4.insertion and accessing ->log(n)
so inserting n ithems ->nlogn
*/

//Iterating using auto keyword
void print(map<int,string> &m)
{
    cout<<m.size()<<endl;
    for(auto &pr : m){
        cout<<pr.first<<" "<<pr.second<<"\n";
    }//accessing and inserting->log(n)
}
int main()
{
    map<int,string> m;
    //Insertion in maps is O(log(n)) operation
    m[1]="abc";
    m[2]="def";
    m[3]="ghi";
    m.insert({4,"xyz"});//other method of i/p
    m[6];//O(log(n)) by default empty string is added
    //check if there is other way as just writing m[k] is of o(logn)
    map<int,string> :: iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        cout<<(*it).first<<" "<<(*it).second<<"\n";
    }
    //all the keys in the map are unique we cant insrt duplicate key
    print(m);
    //-----------------------------------------------------
    //find funct
    //o(logn);
    auto it1=m.find(7);//this returns the iterator of 3
    //but if value is not present then it return m.end;
    if(it1==m.end())
        cout<<"NOT FOUND";
    else
        cout<<(*it1).first<<" "<<(*it1).second;
    //------------------------------------------------------
    //erase
    //Here we can give a>key or b> iterator which is to be erased
    m.erase(3);
    print(m);

    auto it2=m.find(2);
    if(it2!=m.end())
        m.erase(it2);
    print(m);
    //-------------------------------------------------------
    //clear clears the map
    //m.clear();
    //----------------------------------------------------------
    //Now the time complexity of insertion of unordered maps depends uponkeys!
    
    return 0;
}