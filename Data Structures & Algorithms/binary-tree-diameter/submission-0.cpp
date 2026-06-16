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

    int diameter = 0;

    int height(TreeNode* node) {

        // Empty tree has height 0
        if (!node)
            return 0;

        // Height of left subtree
        int leftHeight = height(node->left);

        // Height of right subtree
        int rightHeight = height(node->right);

        // Longest path passing through current node
        diameter = max(diameter, leftHeight + rightHeight);

        // Return height of current subtree
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {

        height(root);

        return diameter;
    }
};