class Codec {
    // Manually jump through the string - Blazing fast hardware-level access!
    TreeNode* deserializeHandler(string &data, int &indx) {
        if (indx >= data.size()) return NULL;
        if (data[indx] == '#') {
            indx += 2; 
            return NULL;
        }

        int val = 0;
        bool isNegative = false;
        
        // Custom string-to-integer parser completely beats stoi() in speed
        if (data[indx] == '-') {
            isNegative = true;
            indx++;
        }
        while (data[indx] != ',') {
            val = val * 10 + (data[indx] - '0');
            indx++;
        }
        indx++; // Skip the comma
        
        if (isNegative) val = -val;

        TreeNode* root = new TreeNode(val);
        root->left = deserializeHandler(data, indx);
        root->right = deserializeHandler(data, indx);
        return root;
    }

public:
    string serialize(TreeNode* root) {
        string res = "";
        serializeHelper(root, res);
        return res;
    }

    void serializeHelper(TreeNode* root, string &res) {
        if (root == NULL) {
            res += "#,";
            return;
        }
        res += to_string(root->val) + ",";
        serializeHelper(root->left, res);
        serializeHelper(root->right, res);
    }

    TreeNode* deserialize(string data) {
        int indx = 0;
        return deserializeHandler(data, indx);
    }
};
