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
    void solve(TreeNode* root,int maxT, int & count){
        if(root == NULL) return;

        if(root->val >= maxT){
            maxT = root->val;
            count= count +1;
        }

        solve(root->left, maxT, count);
        solve(root->right, maxT, count);

    }
public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        int maxT= INT_MIN;
        solve(root,maxT, count);
        return count;
    }
};
