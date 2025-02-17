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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int toReverse = 0;
        while(!q.empty()){
            int sz = q.size();
            vector<int> demo;
            for(int i=0;i<sz;i++){
                TreeNode* node = q.front();
                demo.push_back(node->val);
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(toReverse==1) reverse(demo.begin(), demo.end());
            toReverse = 1 - toReverse;
            ans.push_back(demo);
        }
        return ans;
    }
};
