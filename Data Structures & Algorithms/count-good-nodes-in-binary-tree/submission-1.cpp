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
    int findGood(TreeNode* root, int max, int res){
        if (!root) return 0;

        if (root->val >= max){
            max = root->val;
            res++;
        }
        return res + findGood(root->left, max,0) + findGood(root->right, max,0);
    }

    int goodNodes(TreeNode* root) {
        return findGood(root, root->val, 0);
    }
};
