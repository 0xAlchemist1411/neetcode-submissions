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
    // returns {isBalanced, height}
    pair<bool,int> dfs(TreeNode* root) {
        if (!root) return {true, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        bool balanced = false;
        if(left.first and right.first and abs(left.second - right.second) <= 1){
            balanced = true;
        }
        
        return {balanced, 1 + max(left.second, right.second)};
    }

    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }
};
