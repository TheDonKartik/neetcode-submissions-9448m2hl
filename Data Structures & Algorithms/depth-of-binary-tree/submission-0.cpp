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
        depth++;
        int left = findDepth(root->left, depth);
        int right = findDepth(root->right, depth);
        return max(left,right);
    }

    int maxDepth(TreeNode* root) {
        return findDepth(root , 0);
    }
};
