class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> finalAns;
        vector<long long> conver;
        vector<long long> maxArray;
        long long maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > maxi){
                maxi = nums[i];
            }
            maxArray.push_back(maxi);
        }
        for(int i=0; i<nums.size(); i++){
            long long num = nums[i] + maxArray[i];
            conver.push_back(num);
        }

        finalAns.push_back(conver[0]);
        long long sum = conver[0];
        for(int i=1; i<conver.size(); i++){
            sum += conver[i];
            finalAns.push_back(sum);
        }
        return finalAns;
    }
};