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
    TreeNode* getTree(vector<int>& preorder, vector<int>& inorder, 
                         int pre_begin, int pre_end, int in_begin, int in_end) {
    if(pre_begin > pre_end)
        return NULL;
    int val = preorder[pre_begin];
    TreeNode* root = new TreeNode(val);
    for(int i = in_begin; i <= in_end; ++i) {
        if(inorder[i] == val) {
            root->left = getTree(preorder, inorder, 
                            pre_begin + 1, pre_begin + (i - in_begin), in_begin, i - 1);
            root->right = getTree(preorder, inorder,
                            pre_begin + (i - in_begin) + 1, pre_end, i + 1, in_end);
            break;
        }
    }
    return root;
}
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return getTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};