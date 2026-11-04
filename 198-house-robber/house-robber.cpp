class Solution {
public:
    int fun(int n,vector<int> &dp,vector<int> &nums){
        if(n==0) return nums[n];
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int pick=nums[n]+fun(n-2,dp,nums);
        int not_pick=0+fun(n-1,dp,nums);
        return dp[n]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
      int n=nums.size();  
      vector<int>dp(n,-1);
      return fun(n-1,dp,nums);  
    }
};