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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> ans; 
        if(root == NULL) return ans;
        q.push(root);
        while(!q.empty()) { 
            int len = q.size();
            double avg = 0;
            double count = 0;
            for(int i = 0; i < len; i++) {    
                TreeNode* curr = q.front();
                q.pop();
                avg += (double)curr->val;
                count++;
                if(curr->left != NULL) {
                    q.push(curr->left);
                }
                if(curr->right != NULL) {
                    q.push(curr->right);
                }  
            }
            ans.push_back(avg/count);  
        }
        return ans;
    }
};
