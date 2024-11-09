class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> one, two, ans;
        for (int i = 0; i < A.size(); i++) {
            one.push_back(A[i]);
            two.push_back(B[i]);

            vector<int> first = one;
            vector<int> second = two;

            sort(first.begin(), first.end());
            sort(second.begin(), second.end());
            
            vector<int> v(min(first.size(), second.size()));           
            auto it = set_intersection(first.begin(), first.end(),second.begin(), second.end(),v.begin());
            v.resize(it - v.begin());
            ans.push_back(v.size());
        }
        return ans;
    }
};
