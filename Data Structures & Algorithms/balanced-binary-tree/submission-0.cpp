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
    // returns height if balanced, otherwise -1
    int dfs(TreeNode* root) {
        if (!root) return 0;

        int left = dfs(root->left);
        if (left == -1) return -1;            // left subtree unbalanced

        int right = dfs(root->right);
        if (right == -1) return -1;           // right subtree unbalanced

        if (abs(left - right) > 1) return -1; // current node unbalanced

        return 1 + max(left, right);          // height
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};
