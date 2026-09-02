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
    void helper(TreeNode* root, stack<int> &st){
        if(!root)
            return;
        helper(root->left, st);
        st.push(root->val);
        helper(root->right, st);
    }
    bool isValidBST(TreeNode* root) {
        stack<int> st;
        helper(root, st);
        int post = st.top(); st.pop();
        while(!st.empty()){
            if(post <= st.top())
                return false;
            post = st.top();
            st.pop();
        }
        return true;
    }
};
