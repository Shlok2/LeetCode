class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0){
            return 0;
        }
        
        unordered_set <int> s(nums.begin(),nums.end());
        int ans = INT_MIN;
        for(auto it: nums){
            int prev = it - 1;
            int next = it + 1;
            while(s.find(prev) != s.end()) {s.erase(prev--);}
            while(s.find(next) != s.end()) {s.erase(next++);}
            ans = max(ans, ((next-1) - (prev + 1) + 1) );
        }
        return ans;
    }
};