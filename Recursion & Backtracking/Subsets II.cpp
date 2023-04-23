class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>s;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>v;
        f(0,nums.size(),nums,v);
        return ans;
    }
    void f(int idx,int n,vector<int>&nums,vector<int>&v){
        if(idx==n){
            if(s.find(v)==s.end()){
                s.insert(v);
                ans.push_back(v);
            }
            return;
        }
        v.push_back(nums[idx]);
        f(idx+1,n,nums,v);
        v.pop_back();
        // To skip duplicates while(i+1<nums.size() && nums[i] == nums[i+1])i++;
        f(idx+1,n,nums,v);
    }
};
