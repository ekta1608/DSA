class Solution {
public:
    int f(int row,int col,int m,int n,vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(row>=m || col>=n) return 0;
        if(grid[row][col]) return 0;
        if(row==m-1 && col==n-1) return 1;
        if(dp[row][col]!=-1) return dp[row][col];
        int down=f(row+1,col,m,n,grid,dp);
        int right=f(row,col+1,m,n,grid,dp);
        return dp[row][col]=down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(0,0,m,n,grid,dp);
    }
};