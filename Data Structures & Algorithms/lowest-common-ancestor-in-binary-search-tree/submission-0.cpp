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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // If both p and q have values smaller than the current node,
        // then both nodes must lie in the left subtree.
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // If both p and q have values greater than the current node,
        // then both nodes must lie in the right subtree.
        if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // Otherwise:
        // 1. p is on one side and q is on the other side, OR
        // 2. current node is equal to p or q.
        //
        // In both cases, the current node is the Lowest Common Ancestor.
        return root;
    }
};