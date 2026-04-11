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
        queue<TreeNode*> q;
        vector<vector<int>> res;
        if(!root) return res;
        q.push(root);
        while(!q.empty()){
            vector<int> interM;
            int size = q.size();
            for(int i=size;i>0;i--){
                TreeNode* node = q.front();
                if(node){
                    interM.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
                q.pop();
            }
            if(!interM.empty()) res.push_back(interM);
        }
        return res;
        
    }
};
