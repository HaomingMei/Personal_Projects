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


    int goodNodes(TreeNode* root) {
        return countGood(root, INT_MIN);

    }
    int countGood(TreeNode* node, int currentMax){
        if(node == nullptr){
            return 0;
        }
           // int localMax = std::max(currentMax, node->val);
            return ((node->val >= currentMax) ? 1:0) +countGood(node->left, std::max(currentMax, node->val)) + countGood(node->right, std::max(currentMax, node->val));
        
        
    }
};