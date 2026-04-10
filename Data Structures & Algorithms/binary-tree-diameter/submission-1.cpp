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
    int diameterOfBinaryTree(TreeNode* root) {

        int count = 0;
        getHeight(root,count);
        return count;
    }
private:
    int getHeight(TreeNode* root, int& res){
        if(!root) return 0;
        int leftHeight = getHeight(root->left, res);
        int rightHeight = getHeight(root->right, res);
        res = max(res, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }
};
