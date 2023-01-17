class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 1){
            return {{1}};
        }
        if(numRows == 2){
            return {{1},{1,1}};
        }
        vector<vector<int>> ans;
        ans.push_back({1});
        ans.push_back({1,1});
        int z = 1;

        for(int i = 1;i<=(numRows - 2);i++){
            vector<int> latest = ans[z];
            z++;
            vector<int> v;
            v.push_back(1);
            for(int j = 0;j<(latest.size() - 1); j++){
                v.push_back((latest[j] + latest[j+1]));
            }
            v.push_back(1);
            ans.push_back(v);
        }

        return ans;
    }
};