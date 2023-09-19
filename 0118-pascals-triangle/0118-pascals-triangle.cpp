class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> prev = {1};
        ans.push_back(prev);
        if(numRows == 1){
            return ans;
        }
        for(int i = 1;i<=numRows-1;i++){
            vector<int> temp;
            temp.push_back(1);
            for(int i = 0;i<prev.size() - 1;i++){
                temp.push_back(prev[i] + prev[i+1]);
            }
            temp.push_back(1);
            ans.push_back(temp);
            prev = temp;
        }
        return ans;
    }
};