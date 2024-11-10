class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> m;
        int l = 0, r = 0, maxCount = 0;
        while (r < fruits.size()) {
            m[fruits[r]]++;
            if (m.size() == 3) {
                while (m.size() == 3) {
                    m[fruits[l]]--;
                    if (m[fruits[l]] == 0) m.erase(fruits[l]);
                    l++;
                }
            }
            if (m.size() <= 2) maxCount = max(maxCount, r - l + 1);
            r++;
        }
        return maxCount;
    }
};