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
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;

        ans = max(depth(root->left) + depth(root->right), ans);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return ans;
    }

    int depth(TreeNode* root) {
        if(!root)
            return 0;

        int left = depth(root->left);
        int right = depth(root->right);
        return max(left,right) + 1;
    }
};
