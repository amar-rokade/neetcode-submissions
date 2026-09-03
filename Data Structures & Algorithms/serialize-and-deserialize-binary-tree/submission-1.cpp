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
    int calculateNextIndx(string &data,int &indx){
        string s="";
        for(int i=indx; i< data.size(); i++){
            if(data[i] == ','){ 
                indx=i;
                break;
                }
            s += data[i];
        }
        indx++;
        return stoi(s);
    }
    TreeNode* deserializeHandler(string &data,int &indx) {
        if(data[indx] == '#'){
            indx+=2;
            return NULL;
        }
        if(data.size()-1<indx) return NULL;

        TreeNode* root = new TreeNode(calculateNextIndx(data,indx));

        root->left = deserializeHandler(data,indx);

        root->right = deserializeHandler(data,indx);

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
        cout<<data<<endl;
        int indx = 0;
        return deserializeHandler(data,indx);

    }
};
