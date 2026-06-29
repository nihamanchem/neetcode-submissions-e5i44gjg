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
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);      
    }

    bool dfs(TreeNode* node, int minValue, int maxValue){
        if(!node) return true;
        if(node->val>=maxValue || node->val<=minValue) return false;
        return dfs(node->left, minValue, node->val) && dfs(node->right,node->val, maxValue);
    }
};
