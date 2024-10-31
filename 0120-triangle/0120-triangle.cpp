class Solution {
public:
   
    int minimumTotal(vector<vector<int>>& triangle) {
        // Let's do  Bottom Up Tabulation
        int m = triangle.size();
        vector<vector<int>> dp(m,vector<int>(m, INT_MAX));
        for(int i=0; i<m; i++){
            for(int j=0; j<=i; j++){
                if(i == 0 && j == 0) dp[i][j] = triangle[0][0];
                else{
                    int top = INT_MAX, topLeftCorner = INT_MAX;
                    if(i > 0) top = dp[i - 1][j];
                    if(i > 0 && j > 0) topLeftCorner = dp[i-1][j-1];
                    dp[i][j] = triangle[i][j] + min({top, topLeftCorner});
                }
            }
        }
        return *min_element(dp[m-1].begin(), dp[m-1].end());
    }
};