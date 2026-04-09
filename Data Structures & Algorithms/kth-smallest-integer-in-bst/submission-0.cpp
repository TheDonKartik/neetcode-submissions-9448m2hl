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
    int count(TreeNode* root, int n){
        if (!root) return n;

        n++;
        return (count(root->left, 0) + count(root->right, 0) + n);
    }
    int kthSmallest(TreeNode* root, int k) {
        int l = count(root->left , 0);
        int r = count(root->right, 0);

        if (l+1 == k) return root->val;

        if (k <= l) return kthSmallest(root->left, k);
        return kthSmallest(root->right, k-l-1);
    }
};
