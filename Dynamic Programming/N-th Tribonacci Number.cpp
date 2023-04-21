class Solution {
public:
    int tribonacci(int n) {
        vector<int>t(n+1,-1);
        return f(n,t);
    }
    int f(int n,vector<int>&t){
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        if(t[n]!=-1) return t[n];
        t[n]=f(n-1,t)+f(n-2,t)+f(n-3,t);
        return t[n];
    }
};
