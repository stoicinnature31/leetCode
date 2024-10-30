class Solution {
public:
    int f(int x, int y, int m, int n, vector<vector<int>>& dp) {
        if (x == m - 1 && y == n - 1) return 1;
        else if (x >= m || y >= n) return 0;
        if (dp[x][y] != -1) return dp[x][y];

        int right = f(x, y + 1, m, n, dp);
        int down = f(x + 1, y, m, n, dp);

        return dp[x][y] = (right + down);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(0, 0, m, n, dp);
    }
};