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

    int height(TreeNode* node) {

        // Empty tree has height 0
        if (!node)
            return 0;

        // Get height of left subtree
        int leftHeight = height(node->left);

        // If left subtree is already unbalanced,
        // propagate failure upward
        if (leftHeight == -1)
            return -1;

        // Get height of right subtree
        int rightHeight = height(node->right);

        // If right subtree is already unbalanced,
        // propagate failure upward
        if (rightHeight == -1)
            return -1;

        // Check balance condition at current node
        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        // Return height of current subtree
        return 1 + max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {

        // If height() returns -1,
        // tree is unbalanced
        return height(root) != -1;
    }
};