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
        if(node != nullptr){
            int localMax = std::max(currentMax, node->val);
            int count = (node->val >= currentMax) ? 1:0;

           // int count = countGood(node->left, localMax) + countGood(node->right, localMax);
            //if(node->val >= currentMax){
            //    count+= 1;
            //}
            return count +countGood(node->left, localMax) + countGood(node->right, localMax);
        }
        return 0;
        
    }
};