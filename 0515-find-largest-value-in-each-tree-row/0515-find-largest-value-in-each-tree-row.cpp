/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> ans;
        int row = 0;
        int maxi = INT_MIN;

        if (root == NULL) return ans;

        while (!q.empty()) {
            TreeNode* Front = q.front();
            q.pop();

            if (Front == NULL) {
                ans.push_back(maxi);
                maxi = INT_MIN;
                row++;

                if (!q.empty()) {
                    q.push(NULL);
                }
            } else {
                maxi = max(maxi, Front->val);
                if (Front->left)
                    q.push(Front->left);
                if (Front->right)
                    q.push(Front->right);
            }
        }
        return ans;
    }
};