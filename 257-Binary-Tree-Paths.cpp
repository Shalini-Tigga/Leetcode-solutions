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
    void traversal(TreeNode* root, vector<string>& v,string s){
        if(root == NULL){
            return;
        }
        s += to_string(root->val);
        if( !root->left && !root->right){
            v.push_back(s);
            return;
        }
        s += "->";
        traversal(root->left , v, s);
        traversal(root->right, v, s);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        traversal(root, v,"");
        return v;
    }
};
