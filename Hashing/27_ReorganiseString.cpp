string reorganizeString(string s) {
    unordered_map<int,int> mp;
    for(int i=0;i<s.size();i++)
        mp[s[i]]++;
    priority_queue<pair<int,char>> pq;
    for(auto x:mp)
        pq.push({x.second,x.first});
    string res;
    
    auto block=pq.top();//block the curr char
    res+=block.second;
    block.first--;
    pq.pop();
    
    while(!pq.empty())
    {
        auto top=pq.top();    
        res+=top.second;
        top.first--;
        pq.pop();
        
        if(block.first>0)
            pq.push(block);
        
        
        block=top;//block this for next iteration
    }
    if(block.first>0)//if block  is still there then not possible 
        return "" ;
    return res;
}