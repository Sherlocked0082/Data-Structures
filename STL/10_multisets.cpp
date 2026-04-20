#include<bits/stdc++.h>
using namespace std;
/*
It also uses red black trees 
it allows to enter dupliacte elements
used mostly
in stl there are priority ques then we can use multiset
*/

void print(multiset<string> &s)
{
    cout<<s.size()<<endl;
    for(string value : s)
    {
        cout<<value<<endl;
    }
    // for(auto it=s.begin();it!=s.end();it++)
    // {
    //     cout<<(*it)<<endl;
    // }
    //Both are the same thing
}
int main()
{
    multiset<string> s;
    s.insert("abc");// log(n)
    s.insert("def");
    s.insert("xyz");
    s.insert("abc");
    s.insert("abc");

    print(s);
    //---------------------------------------------
    //finding the elemet
    //It returns the iterator to the first elemet where it is present if duplicates are present
    cout<<"s.find->\n";
    //IMP
    //A.If u have to delete only first occurence use this
    auto it=s.find("abc");
    if(it!=s.end()){
        // cout<<(*it)<<"\n"<<endl;
        s.erase(it);//Here it only deletes that elemt which iterator is pointing 
    }
    print(s);
    //---------------------------------------------
    //erase 
    //HERE IT DELETS ALL the OCCURANCES OF "ABC"
    //B.If u have to delete all occurance use this
    s.erase("abc");
    cout<<"After deleting\n";
    print(s);
    return 0;
}