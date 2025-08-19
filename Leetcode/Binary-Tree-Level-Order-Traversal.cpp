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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root == nullptr){
            return ans;
        }
        q.push(root); // So I don't have to check two conditions in the while loop everytime
        
        int numRoot;
        TreeNode* currentNode;
        while(!q.empty()){
            vector<int> temp;
            numRoot = q.size(); // Row of Root is pushed to the queue, we need to process all of it
            for(int i = 0; i< numRoot; i++){
                currentNode = q.front();
                q.pop();
                if(currentNode->left != nullptr){
                    q.push(currentNode->left);
                }
                if(currentNode->right != nullptr){
                    q.push(currentNode->right);
                }
                temp.push_back(currentNode->val);

            }
            ans.push_back(temp);

        }
        return ans;
    }
};