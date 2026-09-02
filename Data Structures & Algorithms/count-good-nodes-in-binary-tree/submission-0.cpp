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
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode*, int>> q1, q2;
        int count = 0;
        q1.push({root, INT_MIN});
        while(!q1.empty()){
            auto temp = q1.front(); q1.pop();
            if(temp.first->val >= temp.second)
                count++;
            if(temp.first->left)
                q2.push({temp.first->left, max(temp.first->val, temp.second)});
            if(temp.first->right)
                q2.push({temp.first->right, max(temp.first->val, temp.second)});
            if(q1.empty())
                swap(q1, q2);
        }
        return count;
    }
};
