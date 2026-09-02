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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q1, q2;
        q1.push(root);
        string code = "";
        TreeNode* temp;
        while(!q1.empty()){
            temp = q1.front();    q1.pop();
            if(!temp)
                code += "n ";
            else{
                code += to_string(temp->val) + " ";
                q2.push(temp->left);
                q2.push(temp->right);
            }
            if(q1.empty())
                swap(q1, q2);
        }
        return code;
    }

    TreeNode* helper(string &data, int &i){
        string t = "";
        while(data[i] != ' ')
            t += data[i++];
        if(t == "n")
            return NULL;
        return new TreeNode(stoi(t));
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode*> q;
        int i = 0;
        TreeNode *root = helper(data, i), *temp;
        q.push(root);
        i++;
        for(; i<data.size(); i++){
            temp = q.front();   q.pop();
            temp->left = helper(data, i);   i++;
            if(temp->left)
                q.push(temp->left);
            temp->right = helper(data, i);
            if(temp->right)
                q.push(temp->right);
        }
        return root;
    }
};
