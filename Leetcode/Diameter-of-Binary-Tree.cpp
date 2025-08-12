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
    int currentMax = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfsSearch(root);
        return currentMax;
    }

    int dfsSearch(TreeNode* node){
        if(node == nullptr){ // Search until node is nullptr
            return 0;
        }
        int left = dfsSearch(node->left);
        int right = dfsSearch(node->right);
        // Use DFS to find the deepest length of left and right
        // Left + Right for each parent node will be tracked and compared with the current maximum
        currentMax = std::max(currentMax, left+right); // Update if needed
        return 1 + std::max(left, right); // Plus one because we count the current node
        
    }
};