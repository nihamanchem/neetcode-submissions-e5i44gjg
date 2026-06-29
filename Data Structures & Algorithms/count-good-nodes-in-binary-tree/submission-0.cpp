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
        return countGoodNodes(root, root->val); 
        
        
    }
    int countGoodNodes(TreeNode* node, int maxVal){
        if(!node) return 0; 
        int count =0;
        if(node->val>=maxVal) count = 1;
        maxVal = max(maxVal, node->val);
        return count+ countGoodNodes(node->left, maxVal) + countGoodNodes(node->right,maxVal);

    }
};
