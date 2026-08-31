class Solution {
    int solve(TreeNode* root) {
        if (root == NULL) return 0;

        // Check left side. If it's unbalanced (-1), instantly return -1 to stop checking.
        int lh = solve(root->left);
        if (lh == -1) return -1; 

        // Check right side. If it's unbalanced (-1), instantly return -1 to stop checking.
        int rh = solve(root->right);
        if (rh == -1) return -1; 

        // If the current node is unbalanced, return -1
        if (abs(lh - rh) > 1) return -1;

        // Otherwise, return the normal height
        return max(lh, rh) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        // If solve returns -1, it's false (unbalanced). Otherwise, it's true.
        return solve(root) != -1;
    }
};
