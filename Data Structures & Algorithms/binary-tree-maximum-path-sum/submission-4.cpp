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
    int findSum(TreeNode* root){
        if (!root) return 0;

        int l = findSum(root->left) + root->val;
        int r = findSum(root->right) + root->val;

        return max( root->val,max(l,r));
    }

    int find(TreeNode* root, int m){
        if (!root) return m;
        int l = findSum(root->left);
        int r = findSum(root->right);
        int temp = max(root->val, max(l+root->val, r+root->val));
        m = max(max(m, temp), l+r+root->val);
        
        // cout << root->val << " " << m << endl;
        int lmax = find(root->left,INT_MIN);
        int rmax = find(root->right,INT_MIN);
        return max(m, max(lmax, rmax));
    }
    int maxPathSum(TreeNode* root) {
        return find(root, INT_MIN);
    }
};
