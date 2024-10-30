class Solution {
public:
    int f(int x, int y, vector<vector<int>>& grid, vector<vector<int>> &memo){
        if(x == 0 && y == 0) return 1;
        if(x < 0 || y < 0) return 0;
        if(memo[x][y] != -1) return memo[x][y];

        int up = 0, left = 0;
        if(x > 0 && grid[x - 1][y] != 1) up = f(x -1, y, grid, memo);
        if(y > 0 && grid[x][y - 1] != 1) left = f(x, y - 1, grid, memo);
        return memo[x][y] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        //  Let's do bottom up and memoization
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        if(obstacleGrid[m-1][n-1] == 1) return 0;
        return f(m - 1, n - 1, obstacleGrid, memo);
    }
};