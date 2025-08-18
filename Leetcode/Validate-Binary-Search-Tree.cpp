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
        return tryit(root, LONG_MIN, LONG_MAX);// node.val can be -2^31 to 2^31-1
    }

    bool tryit(TreeNode*node, long min, long max){
        if(node == nullptr){
            return true;
        }
        if(node->val <= min || node -> val >= max){
            return false;
        }
        return tryit(node->left, min, node->val) && tryit(node->right, node->val, max);
    }
};