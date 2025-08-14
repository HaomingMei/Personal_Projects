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
    bool isBalanced(TreeNode* root) {
        if(dfsSearch(root) >= 0){
            return true;
        }
        return false;
    }
    int dfsSearch(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        int left = dfsSearch(node->left);
        if(left == -1) return -1;
        int right = dfsSearch(node->right);
        if(right ==-1) return -1;
        if(std::abs(right-left) > 1){
            return -1;
        }
        return 1 + std::max(left, right);
    }
};