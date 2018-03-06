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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            if(node != NULL) {
                if(node->left != NULL || node->right != NULL) {
                    s.push(node->right);
                    s.push(node);
                    s.push(node->left);
                    node->left = node->right = NULL;
                }
                else {
                    result.push_back(node->val);
                }
            }
            
        }
        return result;
    }
};