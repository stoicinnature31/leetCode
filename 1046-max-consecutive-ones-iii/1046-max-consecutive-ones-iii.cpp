class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroCount = 0;
        int l = 0, r = 0;
        int maxSize = 0;
        while(r < nums.size()){
            if(nums[r] == 0) zeroCount++;
            while(zeroCount > k){
                if(nums[l] == 0) zeroCount--;
                l++;
            }
            maxSize = max(maxSize, r - l + 1);
            r++;
        }
        return maxSize;
    }
};