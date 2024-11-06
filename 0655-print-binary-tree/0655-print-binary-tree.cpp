/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int f(TreeNode* root){
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 0;
        
        int left = 1 + f(root->left);
        int right = 1 + f(root->right);

        return max(left, right);
    }
    void fillTheMatrix(TreeNode* root, int r, int c, vector<vector<string>> &res, int height){
        if(root == NULL) return;

        res[r][c] += to_string(root->val);
        fillTheMatrix(root->left,r + 1, c-pow(2,(height - r - 1)), res, height);
        fillTheMatrix(root->right,r + 1,c+pow(2,(height - r - 1)), res, height);

    }
    vector<vector<string>> printTree(TreeNode* root) {
        int height = f(root);
        int m = height + 1;
        int n = pow(2, height + 1) - 1;
        vector<vector<string>> res(m, vector<string>(n, ""));
        int r = 0, c = (n-1)/2;
        res[r][c] += to_string(root->val);

        fillTheMatrix(root->left,r + 1, c-pow(2,(height - r - 1)), res, height);
        fillTheMatrix(root->right,r + 1,c+pow(2,(height - r - 1)), res, height);
        return res;
    }
};