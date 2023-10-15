class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        if(groups.size() == 1){
            return words;            
        }
        
        int x = groups[0];
        vector<int> temp;
        temp.push_back(0);
        
        for(int i =1;i<n;i++){
            if(groups[i] == x){
                continue;
            }
            x = groups[i];
            temp.push_back(i);
                
        }
        
        vector<string> ans;
        for(int i = 0;i<temp.size();i++){
            ans.push_back(words[temp[i]]);
        }
        return ans;
        
        
        // return words;
    }
};