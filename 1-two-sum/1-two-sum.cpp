class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i = 0;i<nums.size();i++){
            int numToFind = target - nums[i];
            if(mp.find(numToFind) != mp.end()){
                ans.push_back(mp[numToFind]);
                ans.push_back(i);
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};