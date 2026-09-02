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
    int maxPathSumHelper(TreeNode* root, long long int &ans) {
        if(root == NULL) return 0;

        int leftSum = max(0,maxPathSumHelper(root->left, ans));
        int rightSum = max(0,maxPathSumHelper(root->right, ans));

        int localSum = leftSum + rightSum + root->val;
        if( localSum  > ans) ans = localSum;

        return root->val + max(leftSum,rightSum );
    }
public:
    int maxPathSum(TreeNode* root) {
       long long  ans = INT_MIN;
       maxPathSumHelper(root,ans);
       return ans;
    }
};
