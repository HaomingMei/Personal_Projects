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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        return isMirrorSame(root->left, root->right);
    }

    bool isMirrorSame(TreeNode* left, TreeNode* right){
        //* Ensure that left and right are either both nullptr
        //* Or both are valid
        if(left == nullptr && right == nullptr){
            return true;
        }
        if(left == nullptr || right == nullptr){
            return false;
        }
        //* If both are valid, test whether they are the same value
        return (left->val == right->val) && isMirrorSame(left->left, right->right) && isMirrorSame(left->right, right->left);

    }
};