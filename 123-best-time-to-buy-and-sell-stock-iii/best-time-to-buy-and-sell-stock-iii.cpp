class Solution {
public:
    int f(int ind,int buy,int cap,vector<int>&arr,int n,vector<vector<vector<int>>> &dp){
        if(cap==0 || ind==n) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        if(buy){
            return dp[ind][buy][cap]=max((-arr[ind]+f(ind+1,0,cap,arr,n,dp)),f(ind+1,1,cap,arr,n,dp));
        }
        else return dp[ind][buy][cap]=max((arr[ind]+f(ind+1,1,cap-1,arr,n,dp)),f(ind+1,0,cap,arr,n,dp));
    }
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,arr,n,dp);
    }
};