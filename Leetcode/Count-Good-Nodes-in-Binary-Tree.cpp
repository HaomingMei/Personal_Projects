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

    //int good = 0;
    int goodNodes(TreeNode* root) {
        return countGood(root, INT_MIN);
     ///   return good;
    }
    int countGood(TreeNode* node, int currentMax){
        if(node == nullptr){
            return 0;
        }
        int count = countGood(node->left, std::max(currentMax, node->val)) + countGood(node->right, std::max(currentMax, node->val));
        if(node->val >= currentMax){
            count+= 1;
        }
        return count;
        
    }
};