class Solution {
public:
    int f(int i, int last, vector<int>& nums, vector<vector<int>> &dp) {
        if (i >= nums.size()) return 0;
        if(dp[i][last + 1] != -1) return dp[i][last + 1];

        int notPick = f(i + 1, last, nums, dp);
        int pick = INT_MIN;
        if (last == -1 || nums[i] > nums[last]) {
            pick = 1 + f(i + 1, i, nums, dp);
        }
        return dp[i][last + 1] = max(pick, notPick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        int last = -1;
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, last, nums, dp);
    }
};