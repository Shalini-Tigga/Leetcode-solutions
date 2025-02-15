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
    bool isvalid(TreeNode* root , long long l , long long h){
        if( !root){
            return true;
        }
        if( root->val <= l || root->val >= h){
            return false;
        }
        return isvalid ( root->left , l , root->val) && isvalid(root->right , root->val, h) ;
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        return isvalid(root,LLONG_MIN, LLONG_MAX);
    }
};

