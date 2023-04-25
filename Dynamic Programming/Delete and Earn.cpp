class Solution {
public:
    vector<int>dp; 
    int deleteAndEarn(vector<int>& nums) {
        dp.resize(nums.size()+1,-1);
        unordered_map<int,int>mp;
        for(auto it:nums) mp[it]++;
        vector<int>v;
        for(auto it:mp) v.push_back(it.first);
        sort(v.begin(),v.end());
        return solve(0,v.size(),v,mp);
    }
    int solve(int idx,int n,vector<int>&v,unordered_map<int,int>&mp){
        if(idx==n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int take=0;
        if(idx+1<v.size() && v[idx]+1==v[idx+1]) take=(v[idx]*mp[v[idx]])+solve(idx+2,n,v,mp);
        else take=(v[idx]*mp[v[idx]])+solve(idx+1,n,v,mp);
        int notTake=0+solve(idx+1,n,v,mp);
        return dp[idx]=max(take,notTake);
    }
};
