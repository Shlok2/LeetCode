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
    void solve(TreeNode* root,vector<vector<int>> &ans,vector<int> &tmp,int x,int& mx){
        if(root == NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL){
            
            if(x+root->val==mx){
                tmp.push_back(root->val);
                ans.push_back(tmp);
                tmp.pop_back();
            }
            return;
        }
        tmp.push_back(root->val);
        solve(root->left,ans,tmp,x+root->val,mx);
        solve(root->right,ans,tmp,x+root->val,mx);
        tmp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int tgt) {
        vector<vector<int>> ans;
        vector<int> tmp;
        // int mx = INT_MIN;
        solve(root,ans,tmp,0,tgt);
        return ans;
    }
};