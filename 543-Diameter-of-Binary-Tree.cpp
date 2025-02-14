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
    int find(TreeNode* root , int &ans){
        if( root == NULL){
            return 0;
        }
        int l = find( root->left  ,ans);
        int r = find( root->right , ans);
        ans = max( ans , 1 + r + l);
        return 1 + max(l , r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if( !root ){
            return 0;
        }
        int ans = 0;
        int h = find( root,ans);
        return ans -1;
    }
};
