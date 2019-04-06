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
    vector<TreeNode*> generateSpecialTrees(int begin, int end) {
        vector<TreeNode*> root;
        if(begin > end) {
            root.push_back(NULL);
        }
        else if(begin == end) {
            TreeNode* node = new TreeNode(begin);
            root.push_back(node);
        }
        else {
            for(int i = begin; i <= end; ++i) {
                vector<TreeNode*> left = generateSpecialTrees(begin, i - 1);
                vector<TreeNode*> right = generateSpecialTrees(i + 1, end);
                int l_size = left.size();
                int r_size = right.size();
                for(int j = 0; j < l_size; ++j) {
                    for(int k = 0; k < r_size; ++k) {
                        TreeNode* node = new TreeNode(i);
                        node->left = left[j];
                        node->right = right[k];
                        root.push_back(node);
                    }
                }
            }
        }
        return root;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) {
            vector<TreeNode*> root;
            return root;
        }
        else 
            return generateSpecialTrees(1, n);
    }
};