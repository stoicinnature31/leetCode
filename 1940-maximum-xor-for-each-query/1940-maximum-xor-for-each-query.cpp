class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> prefixXor;
        int num = 0;
        for(int i=0; i<n; i++){
            num = num ^ nums[i];
            prefixXor.push_back(num);
        }    

        vector<int> ans;
        long long int limit = pow(2, maximumBit);
        int maxi = limit - 1;
        while(n > 0){
            int k = (prefixXor[n-1] ^ maxi);
            if(k < limit) ans.push_back(k);
            prefixXor.pop_back();
            n--;
        }  
        return ans; 
    }
};