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
    int ans = INT_MIN;
    int helper(TreeNode* root){
        if(!root)
            return 0;
        int left = max(0, helper(root->left));
        int right = max(0, helper(root->right));
        int temp = root->val + left + right;
        ans = max(ans, temp);
        return max(temp-left, temp-right);
    }
    int maxPathSum(TreeNode* root) {
        int temp = helper(root);
        return max(ans, temp);
    }
};
