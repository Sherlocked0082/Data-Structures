#include<bits/stdc++.h>
using namespace std;

/*Maps and unorderd maps have same functions
Differences b/w maps and unorderd maps
1.Inbuild implementation
    here hash tables are used(hash values are calculated)
2.Time complexity
    here time complexity is O(1)almost all operation
3.Valid key datatype(int ,longlong,double)(Basically we can use those datat types whose hash table is internally defined)
    we cant use complex data types in unordered types
*/

void print(unordered_map<int,string> &m)
{
    cout<<m.size()<<endl;
    for(auto &pr : m){
        cout<<pr.first<<" "<<pr.second<<"\n";
    }//accessing and inserting->log(n)
}

int main()
{
    unordered_map<int,string> m;
    m[1]="abc";
    m[2]="def";
    m[3]="ghi";
    print(m);
    //here printing is not in lexographical order they are nted in random order
    return 0;
}
//In multimaps we can insert duplicates this is the difference b/w maps and multimaps