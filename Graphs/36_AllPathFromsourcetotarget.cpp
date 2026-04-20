vector<vector<int> > ans;
vector<int> temp;
void DFS(vector<vector<int>>& graph,int i)
{
    temp.push_back(i);
    if(i==graph.size()-1)//target is n-1th node
        ans.push_back(temp);
    for(auto it:graph[i])
    {
        DFS(graph,it);
        temp.pop_back();//if DFS done then pop 
    }
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    DFS(graph,0);
    return ans;
}
