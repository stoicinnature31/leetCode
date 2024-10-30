class Solution {
public:
   
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //  Let's do bottom up using tabulation
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        if (obstacleGrid[m - 1][n - 1] == 1) return 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) memo[i][j] = 1;
                else {
                    int up = 0, left = 0;
                    if (i > 0 && obstacleGrid[i - 1][j] != 1) up = memo[i - 1][j];
                    if (j > 0 && obstacleGrid[i][j - 1] != 1) left = memo[i][j - 1];
                    memo[i][j] = up + left;
                }
            }
        }
        return memo[m - 1][n - 1];
    }
};