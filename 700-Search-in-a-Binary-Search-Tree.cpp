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
    TreeNode* searchBST(TreeNode* root, int k) {
        if( root == NULL){
            return root;
        }
        TreeNode* node = root;
        while(node != NULL){
            if( node->val == k){
                return node;
            }else if ( node->val < k ){
                node = node->right ;
            }else{
                node = node->left;
            }
        }
        return node;
    }
};
