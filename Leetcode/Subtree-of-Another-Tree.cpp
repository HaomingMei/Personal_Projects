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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Level search for the same "root" values, then perform sameTree
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* current;

        while(!q.empty()){
            current = q.front();
            q.pop();

            if(sameTree(current, subRoot)){
                return true;
            }
            // Else don't do anything
            if(current ->left != nullptr){
                q.push(current->left);

            }
            if(current ->right != nullptr){
                q.push(current->right);
            }
        }
        return false; // false if we checked all, but there is no matches

    }
    bool sameTree(TreeNode* p, TreeNode* q){
        if(p == nullptr && q == nullptr){
            return true;
        }
        else if(p == nullptr && q != nullptr){
            return false;

        }
        else if (p != nullptr && q == nullptr){
            return false;
        }
        else{
            if(p->val != q->val){
                return false; // Not equal found, returning false
            }
            return sameTree(p->left, q->left) && sameTree(p->right, q->right); // Case where it's equal, so we keep checking
        }
        return false;
            

    }
};