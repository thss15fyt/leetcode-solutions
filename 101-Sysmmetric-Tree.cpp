/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool checkEqual(TreeNode* left, TreeNode* right) {
        if(left == NULL && right == NULL)
           return true;
        else if((left != NULL && right != NULL && left->val == right->val))
            return checkEqual(left->left, right->right) && checkEqual(left->right, right->left);
        else
            return false;
    }
    
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return checkEqual(root->left, root->right);
    }
};