class Solution {
public:
    int calSum(int left, int right, int top, int bottom, vector<vector<int>>& mat) {
        int sum = 0;
        for (int i = top; i <= bottom; i++) {
            for (int j = left; j <= right; j++) {
                sum += mat[i][j];
            }
        }
        return sum;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int top = max(0, i - k);
                int bottom = min(m - 1, i + k);
                int left = max(0, j - k);
                int right = min(n - 1, j + k);
                ans[i][j] = calSum(left, right, top, bottom, mat);
            }
        }
        return ans;
    }
};