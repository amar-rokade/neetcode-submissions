class Solution {
    // 1. Paste the exact function you just wrote!
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        if(p->val != q->val) return false;
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

public:
    // 2. Traverse the main tree to find a match
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // If the main tree is empty, we can't find a subtree in it
        if(root == NULL) return false;
        
        // Check if the tree starting at the CURRENT node is identical to subRoot
        if(isSameTree(root, subRoot)) {
            return true; 
        }
        
        // If not, keep searching down the left and right branches of the main tree
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
