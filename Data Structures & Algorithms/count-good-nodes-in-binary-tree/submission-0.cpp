class Solution {
public:
    int count = 0;
    void dfs(TreeNode* node, int max_val) {
        if (!node) return;
        if (node->val >= max_val) {
            count++;
            max_val = node->val;
        }
        dfs(node->left, max_val);
        dfs(node->right, max_val);
    }

    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return count;
    }
};