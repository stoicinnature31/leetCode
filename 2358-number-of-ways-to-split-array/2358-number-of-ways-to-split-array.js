/**
 * @param {number[]} nums
 * @return {number}
 */
var waysToSplitArray = function (nums) {
    let validSplits = 0;
    let sum = 0;
    nums.map((i) => sum += i);
    let left = 0;
    let right = sum;
    for (let i = 0; i < nums.length - 1; i++) {
        left += nums[i];
        right -= nums[i];
        if (left >= right) validSplits++;
    }
    return validSplits;
};