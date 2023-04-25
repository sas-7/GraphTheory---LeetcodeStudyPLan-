class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>v;
        f(0,candidates.size(),candidates,target,v);
        return ans;
    }
    void f(int idx,int n,vector<int>& candidates,int target,vector<int>&v){
        if(idx==n){
            if(target==0) ans.push_back(v);
            return;
        }
        if(target>=candidates[idx]){
            v.push_back(candidates[idx]);
            f(idx,n,candidates,target-candidates[idx],v);
            v.pop_back();
        }
        f(idx+1,n,candidates,target,v);
    }
};
