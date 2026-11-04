class Solution {
public:
    int fun(int n,vector<int> &dp,vector<int> & arr){
        if(n==0) return arr[n];
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int pick=arr[n]+fun(n-2,dp,arr);
        int not_pick=0+fun(n-1,dp,arr);
        return dp[n]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n-1,-1);
        vector<int> dp2(n-1,-1);
        vector<int> temp1;
        vector<int> temp2;
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(fun(n-2,dp1,temp1),fun(n-2,dp2,temp2));
    }
};