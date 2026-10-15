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
    vector<int>v;
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k,0);
        return v[k-1];
    }

    void dfs(TreeNode* root, int k, int c) {
        if(!root)
            return;

        if(k == c)
            return;

        dfs(root->left,k,c++);
        v.push_back(root->val);
        dfs(root->right,k,c++);
    }
};
