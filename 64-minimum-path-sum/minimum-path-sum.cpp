class Solution {
public:
    int calc(vector<vector<int>>&grid, int row, int col,vector<vector<int>>&dp) {
        if (row == grid.size()-1 && col == grid[0].size()-1) {
            return grid[row][col];
        }
        if(dp[row][col]!=-1) return dp[row][col];
        int right = INT_MAX;
        if (col + 1 <= grid[0].size() - 1)
            right = calc(grid, row, col + 1,dp);
        int bottom = INT_MAX;
        if (row + 1 <= grid.size() - 1)
            bottom = calc(grid, row + 1, col,dp);
        return dp[row][col]=grid[row][col] + min(right, bottom);
    }
    int minPathSum(vector<vector<int>>& grid) {
         int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
       int ans= calc(grid, 0, 0,dp);
        return ans;
    }
};