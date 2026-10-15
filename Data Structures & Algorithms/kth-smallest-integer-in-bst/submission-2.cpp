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
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
        return ans;
    }

    void dfs(TreeNode* root, int& k) {
        if(!root || k == 0)
            return;

        dfs(root->left,k);

        if(k == 0)
            return;

        k--;
        ans = root->val;
        dfs(root->right,k);
    }
};
