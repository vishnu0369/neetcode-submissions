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
    int goodNodes(TreeNode* root) {
        return dfs(root,INT_MIN);
    }

    int dfs(TreeNode* root, int mx) {
        if(!root)
            return 0;
        int count = 0;

        if(root->val >= mx)
            count++;
        
        int newmx = max(mx,root->val);

        count += dfs(root->left, newmx);
        count += dfs(root->right, newmx);

        return count;
    }
};
