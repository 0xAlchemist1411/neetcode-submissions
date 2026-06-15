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

class Codec {
public:
    void serializeHelper(TreeNode* root, string &res) {
        if (!root) {
            res += "null,";
            return;
        }

        res += to_string(root->val) + ",";
        serializeHelper(root->left, res);
        serializeHelper(root->right, res);
    }


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        serializeHelper(root, res);
        return res;
    }


    TreeNode* deserializeHelper(queue<string> &q) {
        string val = q.front();
        q.pop();

        if (val == "null") return nullptr;

        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserializeHelper(q);
        root->right = deserializeHelper(q);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;

        queue<string> q;
        string temp;

        // Split by comma
        for (char c : data) {
            if (c == ',') {
                q.push(temp); // when a node or null gets completly formed
                temp.clear(); // then clear it in-memory
            } else {
                temp.push_back(c); // building the node/null string
            }
        }

        
        int index = 0;
        return deserializeHelper(q);
    }
};
