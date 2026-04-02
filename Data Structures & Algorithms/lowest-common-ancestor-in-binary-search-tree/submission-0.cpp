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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        
        int r = root->val;
        int a = p->val;
        int b = q->val;

        if ((r >= a && r <= b) || (r <= a && r >= b)) return root;

        if (r > a && r > b) return lowestCommonAncestor(root->left, p,q);
        else return lowestCommonAncestor(root->right, p, q);

        return root;
    }
};
