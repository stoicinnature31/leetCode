class Solution {
public:
    int f(int i, int j, int m, vector<vector<int>>& triangle, vector<vector<int>> &dp){
        if(j >= triangle[i].size() || j < 0) return INT_MAX;
        if(i == m - 1) return triangle[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int down = 0, rightDownCorner = 0;
        down = f(i + 1, j, m, triangle, dp);
        rightDownCorner = f(i + 1,j + 1,m,triangle, dp);

        return dp[i][j] = triangle[i][j] + min({down, rightDownCorner});
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        // Let's do  Bottom Up memoization
        int m = triangle.size();
        vector<vector<int>> dp(m,vector<int>(m, -1));
        return f(0,0,m,triangle, dp);
    }
};