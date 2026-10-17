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
        return build(preorder, inorder, 0, inorder.size()-1,preIndex);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int isStart, int isEnd, int& preIndex) {
        if(isStart > isEnd)
            return NULL;

        // Get the current root value from preorder
        int rootVal = preorder[preIndex];

        // Move to the next preorder element
        preIndex++;

        // Find rootVal in inorder
        int i = isStart;
        for(;i<=isEnd;i++) {
            if(inorder[i] == rootVal)
                break;
        }

        // Create root node
        TreeNode *node = new TreeNode(rootVal);

        // Build left subtree
        node->left = build(preorder, inorder, isStart, i-1, preIndex);

        // Build right subtree
        node->right = build(preorder, inorder, i+1, isEnd, preIndex);

        // Return root
        return node;
    }
};
