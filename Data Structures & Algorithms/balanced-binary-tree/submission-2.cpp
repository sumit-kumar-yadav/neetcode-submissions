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
    pair<bool, int> isBalancedAndHeight(TreeNode* root) {
        if(root == NULL) return make_pair(true, 0);

        pair<bool, int> leftAns = isBalancedAndHeight(root->left);
        pair<bool, int> rightAns = isBalancedAndHeight(root->right);

        pair<bool, int> ans; // isBalance = first , height = second
        ans.first = leftAns.first && rightAns.first 
                    && (abs(leftAns.second - rightAns.second) <= 1)
                    ? true : false; 
        ans.second = 1 + max(leftAns.second, rightAns.second);

        return ans;
    }

    bool isBalanced(TreeNode* root) {
        return isBalancedAndHeight(root).first;
    }
};
