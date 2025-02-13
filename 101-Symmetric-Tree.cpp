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
    bool check( TreeNode* nl , TreeNode* nr){
        if( nl == NULL && nr == NULL){
            return true;
        }
        if(nl== NULL || nr == NULL){
            return false;
        }
        if (nl->val != nr->val) return false; 
        return check(nl->left, nr->right) && check(nl->right, nr->left);
    }
    bool isSymmetric(TreeNode* root) {
        if( root == NULL){
            return true;
        }
        return check(root->left, root->right);
        
    }
};
