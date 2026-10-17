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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++) {
            m[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, inorder.size()-1, preIndex, m);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int isStart, int isEnd, int& preIndex, unordered_map<int,int> &m) {
        if(isStart > isEnd)
            return NULL;

        int rootVal = preorder[preIndex];

        preIndex++;
        int idx = m[rootVal];

        TreeNode *node = new TreeNode(rootVal);

        node->left = build(preorder, inorder, isStart, idx-1, preIndex, m);

        node->right = build(preorder, inorder, idx+1, isEnd, preIndex, m);

        return node;
    }
};
