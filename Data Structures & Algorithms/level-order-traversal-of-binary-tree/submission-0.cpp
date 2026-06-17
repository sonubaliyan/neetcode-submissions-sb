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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        // Stores the final answer
        vector<vector<int>> result;

        // If tree is empty, return empty result
        if (!root) return result;
        
        // Queue is used for BFS traversal
        queue<TreeNode*> q;

        // Start with the root node
        q.push(root);
        
        // Continue until all nodes are processed
        while (!q.empty()) {

            // Number of nodes currently in the queue
            // These nodes belong to the current level
            int size = q.size();

            // Stores values of the current level
            vector<int> level;

            // Process exactly 'size' nodes
            for (int i = 0; i < size; i++) {

                // Get the front node
                TreeNode* node = q.front();
                q.pop();

                // Add its value to current level
                level.push_back(node->val);

                // Add left child for future processing
                if (node->left)
                    q.push(node->left);

                // Add right child for future processing
                if (node->right)
                    q.push(node->right);
            }

            // Store the completed level
            result.push_back(level);
        }

        return result;
    }
};