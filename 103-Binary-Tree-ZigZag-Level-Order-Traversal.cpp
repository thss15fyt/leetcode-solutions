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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;
        stack<TreeNode*> s1, s2;
        s1.push(root);
        bool even = true;
        while(!s1.empty() || !s2.empty()) {
            vector<int> line;
            if(even) {
                while(!s1.empty()) {
                    TreeNode* node = s1.top();
                    s1.pop();
                    line.push_back(node->val);
                    if(node->left) s2.push(node->left);
                    if(node->right) s2.push(node->right);
                }
            }
            else {
                while(!s2.empty()) {
                    TreeNode* node = s2.top();
                    s2.pop();
                    line.push_back(node->val);
                    if(node->right) s1.push(node->right);
                    if(node->left) s1.push(node->left);
                }
            }
            even = !even;
            result.push_back(line);
        }
        return result;
    }
};