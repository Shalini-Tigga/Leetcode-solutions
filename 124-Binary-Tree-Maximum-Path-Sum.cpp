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
    int  find(TreeNode* root,int &ans){
        if(root == NULL){
            return 0 ;
        }
        int l = find( root->left, ans);
        int r = find( root->right, ans);
        ans = max( ans , root->val + l  + r);
        return max( 0 , root->val + max( l , r));
    }
    int maxPathSum(TreeNode* root) {
        if( !root){
            return 0;
        }
        int count = INT_MIN ;
        int val = find( root , count);
        return count;
    }
};
