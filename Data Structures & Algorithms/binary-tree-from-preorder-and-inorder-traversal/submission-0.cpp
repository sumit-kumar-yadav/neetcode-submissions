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
    int findIndex(vector<int>& inorder, int inS, int inE, int target) {
        for(int i = inS; i <= inE; i++) if(inorder[i] == target) return i;
        return -1;
    }

    TreeNode* buildTree(vector<int>& preorder, int preS, int preE, vector<int>& inorder, int inS, int inE) {
        if(preS > preE || inS > inE) return NULL;

        TreeNode* root = new TreeNode(preorder[preS]);
        int rootIndex = findIndex(inorder, inS, inE, preorder[preS]);
        
        root->left = buildTree(preorder, preS+1, preS+rootIndex-inS, inorder, inS, rootIndex-1);
        root->right = buildTree(preorder, preS+rootIndex-inS+1, preE, inorder, rootIndex+1, inE);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};
