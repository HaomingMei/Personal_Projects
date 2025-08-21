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
public:
    TreeNode* lowest = nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        search(root, p, q);
        return lowest;
    }
    int search(TreeNode*node, TreeNode*p, TreeNode*q){
        int count = 0;
        if(node == nullptr || lowest != nullptr){ // return instantly if lowest is no longer nullptr
            return 0;
        }
        if(node->val == p->val || node->val == q->val){
            count += 1;
        }
        count += search(node->left, p, q) + search(node->right, p, q);
        if(lowest == nullptr && count == 2){
            lowest = node; // Since we return from lowest to top
            // This will not change after we set it once
        }
        return count;

    }
};