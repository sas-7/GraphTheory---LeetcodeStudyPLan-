class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        sort(candidates.begin(),candidates.end());
        f(candidates,ans,v,0,target);
        return ans;
    }
    
    void f(vector<int>&candidates,vector<vector<int>>&ans,vector<int> &v,int idx,int target){
        if(target==0){
            ans.push_back(v);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            if(target<candidates[i]) break;
            v.push_back(candidates[i]);
            f(candidates,ans,v,i+1,target-candidates[i]);
            v.pop_back();
        }
    }
};
