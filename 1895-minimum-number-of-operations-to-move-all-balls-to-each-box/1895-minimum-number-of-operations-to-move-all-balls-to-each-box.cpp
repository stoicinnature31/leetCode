class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans;
        for(int i=0; i<n; i++){
            int ways = 0;
            for(int j=0; j<n; j++){
                if(j != i && boxes[j] == '1') ways += abs(j - i);
            }
            ans.push_back(ways);
        }
        return ans;
    }
};