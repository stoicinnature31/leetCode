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
    int minimumOperations(TreeNode* root) {
        int operations = 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL); // Use NULL as a level delimiter
        vector<int> levelArr;

        while (!q.empty()) {
            auto front = q.front();
            q.pop();

            if (front == NULL) {
                // End of current level
                if (!levelArr.empty()) {
                    int size = levelArr.size();
                    vector<int> sortedArr = levelArr;
                    sort(sortedArr.begin(), sortedArr.end());

                    // Map value -> original index
                    unordered_map<int, int> indexMap;
                    for (int i = 0; i < size; i++) {
                        indexMap[levelArr[i]] = i;
                    }

                    vector<bool> visited(size, false);
                    for (int i = 0; i < size; i++) {
                        if (visited[i] || indexMap[sortedArr[i]] == i) continue;

                        int cycles = 0, idx = i;
                        while (!visited[idx]) {
                            visited[idx] = true;
                            idx = indexMap[sortedArr[idx]];
                            cycles++;
                        }
                        operations += (cycles - 1);
                    }

                    levelArr.clear();
                }

                if (!q.empty()) {
                    q.push(NULL); // Add delimiter for the next level
                }
            } else {
                // Process current node
                levelArr.push_back(front->val);
                if (front->left) q.push(front->left);
                if (front->right) q.push(front->right);
            }
        }

        return operations;
    }
};
