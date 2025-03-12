class Solution {
public:
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left) {
            current = current->left;
        }
        return current;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node with only one child or no child
            if (!root->left) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (!root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            TreeNode* temp = minValueNode(root->right);
            
            // Copy the inorder successor's content to this node
            root->val = temp->val;
            
            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }
};
