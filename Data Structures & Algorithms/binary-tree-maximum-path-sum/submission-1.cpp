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
    // Get max pathSum of either (left child + node) or (right child + node)
    // Also update the maxPathSumVal
    int dfs(TreeNode* root, int& maxPathSumVal) {
        if(root == NULL) return 0;

        int leftMax = max(dfs(root->left, maxPathSumVal), 0); // Make sure leftMax / rightMax shouldn't exceed 0
        int rightMax = max(dfs(root->right, maxPathSumVal), 0);

        // Update the maxPathSumVal
        maxPathSumVal = max(maxPathSumVal, root->val + leftMax + rightMax);
        
        // Only return eithrt left or right traversal 
        return root->val + max(leftMax, rightMax);
    }

    int maxPathSum(TreeNode* root) {
        int maxPathSumVal = root->val;
        dfs(root, maxPathSumVal);
        return maxPathSumVal;
    }
};
