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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* rightNode = nullptr;
            int size = q.size();
            
            while(size--){
                TreeNode* node = q.front();
                q.pop();
                if(node){
                    rightNode = node;
                    q.push(node->left);
                    q.push(node->right);
                }
            }

            if(rightNode){
                ans.push_back(rightNode->val);
            }
        }

        return ans;
    }
};









