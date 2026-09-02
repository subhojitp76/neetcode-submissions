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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        TreeNode* temp;
        queue<TreeNode*> q1, q2;
        if(!root)
            return depth;
        q1.push(root);
        while(!q1.empty()){
            temp = q1.front();  q1.pop();
            if(temp->left)
                q2.push(temp->left);
            if(temp->right)
                q2.push(temp->right);
            if(q1.empty()){
                swap(q1, q2);
                depth++;
            }
        }
        return depth;
    }
};
