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
    vector<int> subrob(TreeNode* root){
        if(root == NULL){
            return {0,0};
        }
        vector<int> l = subrob(root->left);
        vector<int> r = subrob(root->right);
        vector<int> res (2);
        res[0] = max(l[0] , l[1]) + max(r[0] , r[1]);
        res[1] = root->val + l[0] + r[0];
        return res;
    }
    int rob(TreeNode* root) {
        vector<int> res = subrob(root);
        return max(res[0] , res[1]);  //(pick , not_pick)
    }
};
