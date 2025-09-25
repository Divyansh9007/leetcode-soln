class Solution {
public:
    int func(int index, int pos, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if (index == triangle.size() - 1) {
            return triangle[index][pos];
        }
        if (dp[index][pos] != INT_MAX) return dp[index][pos];

        int down = triangle[index][pos] + func(index + 1, pos, triangle, dp);
        int diagonal = triangle[index][pos] + func(index + 1, pos + 1, triangle, dp);

        return dp[index][pos] = min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        return func(0, 0, triangle, dp);
    }
};
