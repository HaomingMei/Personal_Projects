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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        st1.push(original);
        st2.push(cloned);
        while(!st1.empty()){
            TreeNode*temp1= st1.top();
            st1.pop();
            if(temp1 == target){
                return st2.top();
            }
            TreeNode*temp2 = st2.top();
            st2.pop();
            if(temp1->left!= NULL){
                st1.push(temp1->left);
                st2.push(temp2->left);
            }
            if(temp1->right != NULL){
                st1.push(temp1->right);
                st2.push(temp2->right);
            }

        }
        return original;
    }
};