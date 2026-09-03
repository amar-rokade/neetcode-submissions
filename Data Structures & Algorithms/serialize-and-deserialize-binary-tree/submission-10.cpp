class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        if(root==NULL) return "N";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())  {
            auto cur = q.front();
            q.pop();
            if(cur==NULL) {
                ans+="N,";
               continue;
            }
            ans+=to_string(cur->val);
            ans+=",";
            q.push(cur->left);
            q.push(cur->right);
        }
        return ans;
    }
    int resolve(string &data, int&i)  {
        if(data[i]=='N') {
            i+=2;
            return INT_MIN;
        }
        bool neg = (data[i]=='-')?true:false;
        if(neg) ++i;
        int val = 0;
        while(i<data.length() && data[i]>='0' && data[i]<='9')  {
            val*=10;
            val+=data[i]-'0';
            ++i;
        }
        if(data[i]==',') ++i;
        return (neg)?-1*val:val;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="N") return NULL;
        int i = 0;
        int k = resolve(data,i);
        queue<TreeNode*>q;
        TreeNode* root = (k==INT_MIN)?NULL: new TreeNode(k);
        if(root) q.push(root);
        while(!q.empty())  {
            TreeNode* cur = q.front();
            q.pop();
            k = resolve(data,i);
            cur->left = (k==INT_MIN)?NULL: new TreeNode(k);
            if(cur->left) q.push(cur->left);
            k = resolve(data,i);
            cur->right = (k==INT_MIN)?NULL: new TreeNode(k);
            if(cur->right) q.push(cur->right);
        }
        return root;
    }
};