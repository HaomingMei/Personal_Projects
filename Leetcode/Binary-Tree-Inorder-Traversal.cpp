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
    vector<int> inorderTraversal(TreeNode* root) {
        // This is my recursive solution:
        //vector<int> myTraversal;
        //inorder(root, myTraversal);
        //return myTraversal;


        // This is my iterative solution
        vector<int> myTraversal;
        stack<TreeNode*> myStack;
        

        TreeNode* currentNode = root;
        while(currentNode!= nullptr || !myStack.empty()){
            if(currentNode != nullptr){
                myStack.push(currentNode);
                currentNode = currentNode->left;
            }else{
                TreeNode* node = myStack.top();
                myStack.pop();
                myTraversal.push_back(node->val);
                currentNode = node->right;
            }
        
        }
        return myTraversal;
    }

    void inorder(TreeNode* node, vector<int> & myTraversal){
        if(node == nullptr){
            return;
        }
        inorder(node->left, myTraversal);
        myTraversal.push_back(node->val);
        inorder(node->right, myTraversal);
        return;
    }
};