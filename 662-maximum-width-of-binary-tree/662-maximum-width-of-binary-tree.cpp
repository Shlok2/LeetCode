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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int maxi = 1;
        
        while(!q.empty()){
            
            int cnt = q.size();
            int start = q.front().second;
            int end = q.back().second;
            
            maxi = max(maxi,(end-start) + 1);
            
            for(int i = 0;i<cnt;i++){
                pair<TreeNode* ,int> p = q.front();
                int ind = p.second - start;
                q.pop();
                
                if(p.first->left){
                    q.push({p.first->left,(long long)2*ind + 1});
                }
                if(p.first->right){
                    q.push({p.first->right,(long long)2*ind + 2});
                }
            }
        }
        return maxi;
    }
};