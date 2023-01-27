class Solution {
public:
    
//     O(N log(N))
        // int ans = -1;
        // sort(nums.begin(),nums.end());
        // for(int i =0;i<nums.size()-1;i++){
        //     if(nums[i] == nums[i+1]){
        //         ans = nums[i];
        //         break;
        //     }
        // }
        // return ans;
//     O(N)
    // By using map
    
    
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);
        
        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};