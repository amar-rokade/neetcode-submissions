class Codec {
    // --- SERIALIZE ENGINE ---
    void serializeHelper(TreeNode* root, ostringstream &out) {
        if (root == NULL) {
            out << "#,"; // Pipe strings directly to the buffer
            return;
        }
        
        out << root->val << ","; // Pipe raw integers directly (no to_string needed!)
        
        serializeHelper(root->left, out);
        serializeHelper(root->right, out);
    }

    // --- DESERIALIZE ENGINE ---
    TreeNode* deserializeHelper(stringstream &ss) {
        string token;
        if (!getline(ss, token, ',') || token == "#") {
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(token));
        root->left = deserializeHelper(ss);
        root->right = deserializeHelper(ss);
        return root;
    }

public:
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root, out);
        return out.str(); // Converts the high-speed buffer into a final string once!
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeHelper(ss);
    }
};
