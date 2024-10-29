class Solution {
public:
    int f(int i, int &sum,int target, vector<int>& nums, int n){
        if(i >= n){
            if(sum == target) return 1;
            else return 0;
        }

        sum += nums[i];
        int plus = f(i + 1,sum,target,nums,n);
        sum -= nums[i];

        sum -= nums[i];
        int minus = f(i + 1,sum,target,nums,n);
        sum += nums[i];
        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), sum = 0;
        return f(0,sum,target,nums,n);
    }
};