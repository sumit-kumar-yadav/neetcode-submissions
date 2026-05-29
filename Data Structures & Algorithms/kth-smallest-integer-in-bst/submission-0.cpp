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
    int count = 1;

    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return -1;

        int leftAns = kthSmallest(root->left, k);
        if(leftAns != -1) return leftAns;
        
        if(count == k) return root->val;
        else count++;

        return kthSmallest(root->right, k);
    }
};
