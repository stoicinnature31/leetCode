class Solution {
public:
    int f(int i, int target, vector<int>& nums, vector<vector<int>> &dp){
        if(target == 0) return 1;
        if(i == nums.size() - 1) return nums[i] == target;

        if(dp[i][target] != -1) return dp[i][target];
        //Exclude
        bool notTake = f(i + 1,target, nums, dp);
        // Include
        bool take = 0;
        if(target >= nums[i]) take = f(i + 1,target - nums[i], nums, dp);

        return dp[i][target] = (take || notTake);
    }
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);        
        if (total & 1) return false;
        int target = total / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        return f(0, target, nums, dp);
    }
};