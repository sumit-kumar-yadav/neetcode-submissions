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
    pair<int,int> heightAndDiameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return make_pair(0, 0);

        pair<int,int> left = heightAndDiameterOfBinaryTree(root->left);
        pair<int,int> right = heightAndDiameterOfBinaryTree(root->right);

        pair<int,int> ans;
        ans.first = 1 + max(left.first, right.first);
        ans.second = max((left.first + right.first), max(left.second, right.second));

        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return heightAndDiameterOfBinaryTree(root).second;
    }
};
