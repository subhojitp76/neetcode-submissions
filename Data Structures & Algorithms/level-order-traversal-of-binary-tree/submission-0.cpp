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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return result;
        vector<int> level;
        queue<TreeNode*> q1, q2;
        q1.push(root);
        TreeNode* temp;
        while(!q1.empty()){
            temp = q1.front();    q1.pop();
            level.push_back(temp->val);
            if(temp->left)
                q2.push(temp->left);
            if(temp->right)
                q2.push(temp->right);
            if(q1.empty()){
                swap(q1, q2);
                result.push_back(level);
                level = {};
            }
        }
        return result;
    }
};
