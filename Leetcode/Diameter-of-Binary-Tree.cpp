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
    int currentMax=0;
    int diameterOfBinaryTree(TreeNode* root) {
        // Review
        dfsSearch(root);
        return currentMax;
    }
    int dfsSearch(TreeNode* node){
        // Base Case: 
        if(node == nullptr){
            return 0; // because there is no distance between the node and its parent

        }
        int leftDistance =  dfsSearch(node->left);
        int rightDistance =  dfsSearch(node->right);

        currentMax = std::max(currentMax, leftDistance+rightDistance); // See if the current node has the longest path
        return 1 + std::max(leftDistance, rightDistance); // Case to take the longest path between left and right and to the parent, assuming parent node is the longest path
    }
};