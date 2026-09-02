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
    int dia = 0;
    int height(TreeNode* root, int h){
        if(!root)
            return h - 1;
        int l = height(root->left, h+1);
        int r = height(root->right, h+1);
        dia = max(dia, (r + l - h - h));
        // cout << root->val << ": " << l << " " << r << " " << dia << endl;
        return max(l, r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int temp = height(root, -1);
        return dia;
    }
};
