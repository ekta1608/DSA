class Solution {
public:
    int f(int ind,int buy,int fee,vector<int> &arr,vector<vector<int>>&dp,int n){
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
            return dp[ind][buy]=max((-arr[ind]+f(ind+1,0,fee,arr,dp,n)),f(ind+1,1,fee,arr,dp,n));
        }
        else{
            return dp[ind][buy]=max((arr[ind]-fee+f(ind+1,1,fee,arr,dp,n)),f(ind+1,0,fee,arr,dp,n));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return f(0,1,fee,prices,dp,n);
    }
};