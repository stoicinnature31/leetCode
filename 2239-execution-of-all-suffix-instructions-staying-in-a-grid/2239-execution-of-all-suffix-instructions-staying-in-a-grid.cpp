class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;

        for (int i = 0; i < s.size(); i++) {
            int count = 0;
            int x = startPos[0], y = startPos[1];
            for (int j = i; j < s.size(); j++) {
                if (s[j] == 'R' && y + 1 < n) {
                    count++;
                    y++;
                } 
                else if (s[j] == 'L' && y > 0) {
                    count++;
                    y--;
                } 
                else if (s[j] == 'U' && x > 0) {
                    count++;
                    x--;

                } 
                else if (s[j] == 'D' && x + 1 < n) {
                    count++;
                    x++;
                } 
                else
                    break;
            }
            ans.push_back(count);
        }
        return ans;
    }
};