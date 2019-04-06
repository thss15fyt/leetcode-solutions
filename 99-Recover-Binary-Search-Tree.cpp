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
    void swap_node(TreeNode* node1, TreeNode* node2) {
        int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;
    }
    bool inorder_travel_recover(TreeNode* node, TreeNode*& last, TreeNode*& bigger) {
        if(!node)
            return false;
        if(node->left)
            if(inorder_travel_recover(node->left, last, bigger)) 
                return true;
        if(bigger != NULL) {
            if(node->val >= bigger->val) {
                swap_node(bigger, last);
                return true;
            }
        }
        else {
            if(node->val < last->val) {
                bigger = last;
            }
        }
        last = node;
        if(node->right)
            if(inorder_travel_recover(node->right, last, bigger)) 
                return true;
        return false;
    }
    
public:
    void recoverTree(TreeNode* root) {
        TreeNode *last, *bigger;
        last = new TreeNode(INT_MIN);
        bigger = NULL;
        if(!inorder_travel_recover(root, last, bigger)) {
            swap_node(last, bigger);
        }
    }
};