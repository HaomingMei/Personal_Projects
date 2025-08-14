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
        //Review
        vector<int> ans;
        stack<TreeNode*> st;

        TreeNode* curr = root;

        while(curr != nullptr || !st.empty()){
            if(curr != nullptr){
                st.push(curr);
                curr = curr ->left;
            }
            else{
                TreeNode* temp = st.top();
                if(temp ->right != nullptr)
                {
                    curr = temp->right;
                    temp ->right = nullptr; // Make it nullptr, so next time we add the "temp" node to the traversed list
                }
                else{
                    st.pop();
                    ans.push_back(temp->val);
                    curr = temp->right;

                }
            }

        }
        return ans;
    }
};