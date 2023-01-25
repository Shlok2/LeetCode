class Solution {
public:
    
    static bool sortAcc1(vector<int> &v1,vector<int> &v2){
        if(v1[0] != v2[0]){
            return v1[0] < v2[0];
        }
        return v1[1]<v2[1];
    }
    
    static bool sortAcc(vector<int> &v1,vector<int> &v2){
        return v1[1]<v2[1];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& v) {
        
        sort(v.begin(),v.end(),sortAcc1);
        
        vector<vector<int>> ans2;
        vector<vector<int>> ans1;
        // for(int i = 0;i<v.size();i++){
        //     cout<<v[i][0]<<" "<<v[i][1]<<endl;
        // }
        int n = v.size();
        ans1.push_back(v[0]);
        
        if(v.size() == 1){
            return ans1;
        }
        
        int i = 1;
        
        while(i<=n-1){
            vector<int> t = ans1.back();
            vector<int> temp;
            if(t[1] >= v[i][0]){
                temp.push_back(t[0]);
                temp.push_back(max(t[1],v[i][1]));
                ans1.push_back(temp);
                i++;
            }
            else{
                ans1.push_back(v[i]);
                i++;
            }
        }
        sort(ans1.begin(),ans1.end());
        
        int j = 0;
        bool flag = false;
        
        while(j <= n-1){
            
            // if(j == n-1 && flag == true){
            //     ans2.push_back(ans1[j]);
            //     break;
            // }
            
            if(j == n-1){
                ans2.push_back(ans1[j]);
                break;
            }
            
            
            if(ans1[j][0] == ans1[j+1][0]){
                j++;
            }
            else{
                ans2.push_back(ans1[j]);
                j++;
            }
        }
        
        return ans2;
    }
};