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
        vector<int> ans;
        std::stack<TreeNode*> st;
        TreeNode* curr = root;
        while(curr!= nullptr || !st.empty()){
            if(curr!=nullptr){
                st.push(curr);
                curr = curr ->left;
            }
            else{
                if(st.top()->right != nullptr){
                    curr = st.top()->right;
                    st.top()->right = nullptr; // set to nullptr so we don't re process

                }
                else{
                    ans.push_back(st.top()->val);
                    curr = st.top()->right; // set to nullptr so it comes back to else case
                    st.pop();
                   // st.top()->right = nullptr;
                }
            }
           
        }
        return ans;
    }
};