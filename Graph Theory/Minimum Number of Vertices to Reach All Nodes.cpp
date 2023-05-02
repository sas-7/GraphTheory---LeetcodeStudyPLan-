class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool>incomingEdge(n,false);
        for(auto it:edges) {
            incomingEdge[it[1]]=true;
        }
        vector<int>ans;
        for (int i=0;i<n;i++){
            if(!incomingEdge[i]) ans.push_back(i);
        }
        return ans;
    }
};
