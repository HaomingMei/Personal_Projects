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
    vector<int> postorderTraversal(TreeNode* root) {
        // This is code for recursive method
        //vector<int> myTraversal;
        //postorder(root, myTraversal);
        //return myTraversal;

        // Code for iterative method:
        vector<int> myTraversal;
        stack<TreeNode*> myStack;
        TreeNode* myNode = root;
        TreeNode* lastVisited = nullptr; // Need this node to ensure that
        if(myNode == nullptr){
            return myTraversal;
        }
        while(myNode!= nullptr || !myStack.empty()){
          if(myNode != nullptr){ 
            myStack.push(myNode);
            myNode = myNode->left; // Process the left node first
          }
          else{ // Goes here when leftmost node is nullptr, and we need to check the right
            TreeNode* node = myStack.top(); // Since the left most node of the previous parent is nullptr, we need to go back to the parent 
            // Then, check the right children
            if(node->right != nullptr && lastVisited != node->right){ // Right Exist Case, and I haven't visited
                myNode = node->right;
            }
            else{ // Right Does not Exist case
                myTraversal.push_back(node->val);
                myStack.pop();
                lastVisited = node;
            }
          }
        }
        return myTraversal;
    }
    void postorder(TreeNode* node, vector<int>& myTraversal){
        if(node == nullptr){
            return;
        }
        postorder(node->left, myTraversal);
        postorder(node->right, myTraversal);
        myTraversal.push_back(node->val);
        return;
    }
};

