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
        vector<int> v;
        if(root== NULL)return v;

        queue<TreeNode*> dq;
        dq.push(root);

        while(!dq.empty()){
            v.push_back(dq.back()->val);
            int n = dq.size();
            for(int i=0; i<n; i++){
                TreeNode* front = dq.front();
                dq.pop();
                if(front->left)dq.push(front->left);
                if(front->right)dq.push(front->right);
            }
           
        }
        return v;
    }
};
