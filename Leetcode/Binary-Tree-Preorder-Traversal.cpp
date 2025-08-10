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
    vector<int> preorderTraversal(TreeNode* root) {
        //Recursive Solution
        //vector<int> myTraversal;
        //preorder(root, myTraversal);
        //return myTraversal;   
        vector<int> myTraversal;
        stack<TreeNode*> myStack;
        TreeNode* curr = root;
        while(curr != nullptr || !myStack.empty()){
            if(curr!= nullptr){
                myStack.push(curr);
                myTraversal.push_back(curr->val);
                curr = curr->left;
            }
            else{
                TreeNode* node = myStack.top();
                myStack.pop();
                curr = node->right;

            }
        }
        return myTraversal;
    }
    void preorder(TreeNode* node, vector<int> &myTraversal){
        if(node == nullptr){
           
            return;
        }
        else{
            myTraversal.push_back(node->val);
            preorder(node->left, myTraversal);
            preorder(node->right, myTraversal);
        }
        
    }
};