class Solution {
public:
    set<vector<int>>s;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans; 
        vector<int> v;
        fun(ans,0,nums,v);
        return ans;
    }
     void fun(vector<vector<int>> &ans,int i,vector<int>&nums,vector<int>&v){
        if(i==nums.size()){
            if(s.find(v) == s.end()){
                s.insert(v);
                ans.push_back(v);   
            }
            return;
        }
        //Take or pic the particular index into the subsequence
        v.push_back(nums[i]);
        fun(ans,i+1,nums,v);
        //Backtrack
        v.pop_back();
        //Not Take
       // To skip duplicates while(i+1<nums.size() && nums[i] == nums[i+1])i++;
        fun(ans,i+1,nums,v);
    }
};
