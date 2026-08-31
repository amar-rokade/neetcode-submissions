class Solution {
    int solve(TreeNode* root, int& ans) {
        // Base case: null nodes have a height of 0
        if(root == NULL) return 0;
        
        // Recursively find the height of the left and right subtrees
        int left = solve(root->left, ans);
        int right = solve(root->right, ans);
        
        // The diameter passing through this node is left_height + right_height
        // Update the maximum diameter found so far
        ans = max(ans, left + right);
        
        // Return the height of the tree rooted at this node
        return max(left, right) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
       int ans = 0;
       solve(root, ans); // We don't need to store it in 'temp', just execute it
       return ans;
    }
};
