class Solution {
public:
    int fib(int n) {
        vector<int>t(n+1,-1);
        return f(n,t);
    }
    int f(int n,vector<int>&t){
        if(n<=1) return n;
        if(t[n]!=-1) return t[n];
        t[n]=f(n-1,t)+f(n-2,t);
        return t[n];
    }
};