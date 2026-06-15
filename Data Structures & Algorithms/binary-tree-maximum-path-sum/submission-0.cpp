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
    int dfs(TreeNode* root, int& maxPathSum){
        if(!root){
            return 0;
        }

        // calculating max of left and right, and ignoring -ve values
        int leftMax = max(0, dfs(root->left, maxPathSum));
        int rightMax = max(0, dfs(root->right, maxPathSum));

        maxPathSum  = max(maxPathSum, root->val + leftMax + rightMax);

        return root->val + max(leftMax, rightMax);
    }

    int maxPathSum(TreeNode* root) {
        int maxPathSum = INT_MIN;
        dfs(root, maxPathSum);
        return maxPathSum;
    }
};
