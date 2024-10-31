class Solution {
public:
    int f(int x, int y, vector<vector<int>>& grid, vector<vector<int>> &dp){
        if(x >= grid.size() || y >= grid[0].size()) return INT_MAX;
        if (x == grid.size() - 1 && y == grid[0].size() - 1) return grid[x][y];
        if(dp[x][y] != -1) return dp[x][y];

        //Since left and top movement will increase path sum unnecessary
        int right = 0,down = 0;
        right = f(x, y+1, grid,dp);
        down = f(x + 1, y, grid, dp);
        return dp[x][y] =  grid[x][y] + min(right, down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        //Bottom up with memoization
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return f(0,0,grid, dp);
    }
};