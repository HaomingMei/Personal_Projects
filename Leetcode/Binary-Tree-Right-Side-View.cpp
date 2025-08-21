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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root == nullptr){
            return ans;
        }
        q.push(root);
        ans.push_back(root->val);

        while(!q.empty()){ // Level Search because length of the answer is equal to the depth
            int size = q.size();
            TreeNode* rightMost =  nullptr;// Per Level
            for(int i = 0; i< size; i++){ // Force 1 append per level
                TreeNode* current = q.front();
                if(current ->right != nullptr){
                    if(rightMost== nullptr){
                        rightMost = current->right;
                    }
                    q.push(current->right);
                    
                }
                if(current->left != nullptr){
                    if(rightMost== nullptr){
                        rightMost = current->left;
                    }
                    q.push(current->left);
                    
                }
                q.pop();
            }
            if(rightMost != nullptr){
                ans.push_back(rightMost->val);
            }
        }
        return ans;
    }
};