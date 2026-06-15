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


    TreeNode* deserializeHelper(vector<string> &nodes, int &index) {
        if (index >= nodes.size() || nodes[index] == "null") { // check if the first node or any node is null. or not
            index++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodes[index++]));
        root->left = deserializeHelper(nodes, index);
        root->right = deserializeHelper(nodes, index);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string temp;

        // Split by comma
        for (char c : data) {
            if (c == ',') {
                nodes.push_back(temp); // when a node or null gets completly formed
                temp.clear(); // then clear it in-memory
            } else {
                temp.push_back(c); // pushing each char, until the node/null gets formed
            }
        }

        
        int index = 0;
        return deserializeHelper(nodes, index);
    }
};
