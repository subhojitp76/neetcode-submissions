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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int il, int ir, int &p){
        cout << il << " " << ir << endl;
        if(il > ir)
            return NULL;
        int t = il;
        for(; t<=ir; t++){
            if(inorder[t] == preorder[p])
                break;
        }
        TreeNode* root = new TreeNode(preorder[p++]);
        root->left = helper(preorder, inorder, il, t-1, p);
        root->right = helper(preorder, inorder, t+1, ir, p);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int p = 0;
        return helper(preorder, inorder, 0, preorder.size()-1, p);
    }
};
