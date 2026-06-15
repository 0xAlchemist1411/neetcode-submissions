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
    void dfs(TreeNode* root, int nodeVal, int &good){
        if(root->val >= nodeVal){
            good++;
        }

        if(root->left){
            dfs(root->left, max(nodeVal, root->val), good);
        }

        if(root->right){
            dfs(root->right, max(nodeVal, root->val), good);
        }
    }

    int goodNodes(TreeNode* root) {
        if(!root){
            return 0;
        }

        int good = 0;
        dfs(root, root->val, good); // intially the main root's value is a good node by default 
        return good;
    }
};
