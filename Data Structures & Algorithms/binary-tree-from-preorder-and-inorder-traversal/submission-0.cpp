class Solution {
    TreeNode* buildTreeHelper(vector<int>& preorder, int& preIndex, int inStart, int inEnd, unordered_map<int, int>& inMap) {
        // Base Case: If the boundaries cross, this subtree is empty (the "cage" closed)
        if (inStart > inEnd) {
            return NULL;
        }

        // 1. Grab the current root from preorder
        int rootVal = preorder[preIndex];
        TreeNode* root = new TreeNode(rootVal);
        
        // 2. Increment the global-style index for the next recursive call
        preIndex++;

        // 3. Find exactly where this root splits the inorder array (O(1) lookup)
        int splitIndex = inMap[rootVal];

        // 4. Mathematically bound the left and right recursive calls
        // The left subtree gets everything strictly to the left of the split
        root->left = buildTreeHelper(preorder, preIndex, inStart, splitIndex - 1, inMap);
        
        // The right subtree gets everything strictly to the right of the split
        root->right = buildTreeHelper(preorder, preIndex, splitIndex + 1, inEnd, inMap);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        
        // Pre-process the inorder array to eliminate O(N) searches later
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        // Initialize our preorder index and pass it by reference
        int preIndex = 0; 
        
        // Start the recursion with the widest possible boundaries
        return buildTreeHelper(preorder, preIndex, 0, inorder.size() - 1, inMap);
    }
};
