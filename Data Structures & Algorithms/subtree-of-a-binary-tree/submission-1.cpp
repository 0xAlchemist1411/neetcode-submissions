class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;

        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({p, q});

        while (!st.empty()) {
            auto [n1, n2] = st.top();
            st.pop();

            if (!n1 && !n2) continue;
            if (!n1 || !n2) return false;
            if (n1->val != n2->val) return false;

            st.push({n1->left, n2->left});
            st.push({n1->right, n2->right});
        }
        return true;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            // check if subtree matches here
            if (isSameTree(node, subRoot)) return true;

            // push children to continue DFS
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }

        return false;
    }
};
