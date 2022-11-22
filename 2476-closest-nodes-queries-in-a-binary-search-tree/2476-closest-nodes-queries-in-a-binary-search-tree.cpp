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
    
    void inorder(vector<int> &v,TreeNode* root){
        if(root == NULL){
            return;
        }
        inorder(v,root->left);
        v.push_back(root->val);
        inorder(v,root->right);
    }
     
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> v;
        inorder(v,root);
        vector<vector<int>> ans;
        int n = v.size();
        
        for(auto q: queries){
            int mn = -1,mx = -1;
            
            // mn/mx -> lower bound and upper bound *index*
            if(v[0] <= q){
                mn = (lower_bound(v.begin(),v.end(),q)) - v.begin();    
            }
            
            if(q <= v[n-1]){
                mx = (upper_bound(v.begin(),v.end(),q)) - v.begin();    
            }
            
            if(mn > 0 && mn >= v.size()){mn--;}
            if(mn >= 0 && v[mn] > q){mn--;}
            if(mx > 0 && v[mx-1] == q){mx--;}
            
            if(mn != -1){
                mn = v[mn];
            }
            if(mx != -1){
                mx = v[mx];
            }
            
            ans.push_back({mn,mx});
        }
        
        
        return ans;
    }
};