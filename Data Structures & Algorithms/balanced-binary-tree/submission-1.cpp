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
    int findDepth(TreeNode* root, int depth){
        if (!root) return depth;

        depth ++;
        int left = findDepth(root->left, depth);
        int right = findDepth(root->right, depth);
        return max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        int left = findDepth(root->left, 0);
        int right = findDepth(root->right, 0);

        if (abs(left - right) > 1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};
