class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>v;
        v.push_back(0);
        dfs(0,v,graph,n-1);
        return ans;
    }
    void dfs(int s,vector<int>v,vector<vector<int>>& graph,int n){
        if(s==n) ans.push_back(v);
        for(auto it:graph[s]){
            v.push_back(it);
            dfs(it,v,graph,n);
            v.pop_back();
        }
    }
};
