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
        if(root == NULL) return "#,";
        string s = to_string(root->val) + ',';
        return s + serialize(root->left) + serialize(root->right); 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeHandler(ss);

    }
};
