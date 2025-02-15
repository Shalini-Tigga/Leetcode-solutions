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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if( !root ){
            return res;
        }
        queue<pair < TreeNode* , pair<int, int>>> q;
        map<int , map<int, multiset<int>>> m;
        q.push({root, {0,0}});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int reference = q.front().second.first;
            int level = q.front().second.second;
            q.pop();
            m[reference][level].insert(node->val);
            if( node->left != NULL){
                q.push({node->left, {reference - 1, level + 1}});
            }
            if( node->right != NULL){
                q.push({node->right, {reference + 1, level + 1}});
            }
        }
        for(auto it : m){
            vector<int> v;
            for(auto ig : it.second){
                for(auto k : ig.second){
                    v.push_back(k);
                }
            }
            res.push_back(v);
        }
        return res;
    }
};
