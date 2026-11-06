class Solution {
public:

    // int f(int row,int col,int m,int n,vector<vector<int>>& grid,vector<vector<int>> &dp){
    //     if(row==m-1 && col==n-1) return grid[row][col];
    //     if(row>=m || col>=n) return 1e9;
    //     if(dp[row][col]!=-1) return dp[row][col];
    //     int down=f(row+1,col,m,n,grid,dp);
    //     int right=f(row,col+1,m,n,grid,dp);
    //     return dp[row][col]=grid[row][col]+min(down,right);
    // }
    // int minPathSum(vector<vector<int>>& grid) {
    //     int m=grid.size();
    //     int n=grid[0].size();
    //     vector<vector<int>>dp(m,vector<int>(n,-1));
    //     return f(0,0,m,n,grid,dp);
    // }
    
    //tabulation
    int minPathSum(vector<vector<int>> &grid){
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[m-1][n-1]=grid[m-1][n-1];
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) continue;
                int down=(i+1<m)?dp[i+1][j]:1e9;
                int right=(j+1<n)?dp[i][j+1]:1e9;
                dp[i][j]=grid[i][j]+min(down,right);
            }
        }
        return dp[0][0];
    }
};