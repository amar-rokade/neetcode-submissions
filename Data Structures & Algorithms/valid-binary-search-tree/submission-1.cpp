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
   bool solve(TreeNode* root,int minVal, int maxVal ){
        if(root == NULL) return true;

        if(root->val <= minVal || root->val >= maxVal)return false;

        return solve(root->left,minVal, root->val) && solve(root->right, root->val, maxVal);
        
   }
public:
    bool isValidBST(TreeNode* root) {
        return solve(root, INT_MIN, INT_MAX);

    }
};
