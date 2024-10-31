class Solution {
public:
   
    int minPathSum(vector<vector<int>>& grid) {
        //Bottom up with Tabulation
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(i == 0 && j == 0) dp[i][j] = grid[0][0];
                else{
                    int left = INT_MAX,top = INT_MAX;
                    if(j > 0) left = dp[i][j-1];
                    if(i > 0) top = dp[i-1][j];
                    dp[i][j] = grid[i][j] + min(left,top);
                }
            }
        }
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};