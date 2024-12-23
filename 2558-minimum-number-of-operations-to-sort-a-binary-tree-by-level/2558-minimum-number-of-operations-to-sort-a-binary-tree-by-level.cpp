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
     int findMinSwaps(vector<int>& values){
        int min_swaps=0;

        //Store K->Value...V->Actual_Idx Ordered Map
        map<int,int> sorted_map;
        int n=values.size();
        for(int j=0;j<n;++j)
            sorted_map[values[j]]=j;

        //Sort the array to know the expected index
        sort(values.begin(),values.end());

        vector<bool> visited(n,false);//This marks already processed indices
        int iteration=0;    //Row number of Map
        for(auto& [val,idx]: sorted_map){
            if(visited[idx]){//Don't process if already done
                iteration++;
                continue;
            }    

            visited[idx]=true;
            int len=1;//Find length of cycle
            while(idx!=iteration){
                idx = sorted_map[values[idx]];
                visited[idx]=true;
                len++;
            }
            min_swaps += len-1;//Add no of swaps for the current loop
            iteration++;
        }
        return min_swaps;
    }
    int minimumOperations(TreeNode* root) {
         queue<TreeNode*> q;
        q.push(root);

        int min_swaps=0;
        while(!q.empty()){
            int size=q.size();
            vector<int> values;
            for(int i=0;i<size;++i){
                TreeNode* curr = q.front();
                q.pop();

                values.push_back(curr->val);
                if(curr->left)  q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            min_swaps += findMinSwaps(values);
        }
        return min_swaps;
    }
};