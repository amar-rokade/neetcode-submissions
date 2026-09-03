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
    void serializeHelper(TreeNode* root, string &res) {
        if (root == NULL) {
            res += "#,"; // Append in place!
            return;
        }
        
        res += to_string(root->val) + ",";
        
        serializeHelper(root->left, res);
        serializeHelper(root->right, res);
    }
    TreeNode* deserializeHandler(stringstream &ss) {
        string token;

        if (!getline(ss, token, ',')) {
            return NULL;
        }

        if (token == "#") {
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(token));

        root->left = deserializeHandler(ss);

        root->right = deserializeHandler(ss);

        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res="";
        serializeHelper(root,res);
        return res;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeHandler(ss);

    }
};
