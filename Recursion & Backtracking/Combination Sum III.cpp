class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v;
        f(v,1,k,n);
        return ans;
    }
    void f(vector<int>&v,int idx,int k,int n) {
        if(v.size()==k && n==0){
            ans.push_back(v);
            return;
        }
        for(int i=idx;i<10;i++){
            if(v.size()>k && i>n) break;
            v.push_back(i);
            f(v,i+1,k,n-i);
            v.pop_back();
        }  
    }
};
