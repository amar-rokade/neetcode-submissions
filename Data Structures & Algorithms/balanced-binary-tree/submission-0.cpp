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

    int solve(TreeNode* root, bool &flag){
         if(root == NULL) return 0;

        int lh = solve(root->left,flag);
        int rh= solve(root->right,flag);

        if(abs(lh-rh)> 1)flag =  false;

        return max(lh, rh) +1;
    }
public:
    bool isBalanced(TreeNode* root) {
        bool flag = true;
        solve(root, flag);
        return flag;
    }
};
