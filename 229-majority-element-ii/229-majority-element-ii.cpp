class Solution {
public:

    // number of elements that can be greater than n/3 are only 2.
    // eg -> [2,2,1,1,1,3,3,3] -> n/2 = 2
    // ans = [1,3] (2 numbers (1,2)), similarly see any test case.
    vector<int> majorityElement(vector<int>& nums) {
        
        if(nums.size() == 1){
            return nums;
        }

        vector<int> ans;
        int ele1 = INT_MIN,ele2 = INT_MIN;
        // c -> cnt;
        int c1 = 0,c2 = 0;
        for(auto num:nums){
            if(num == ele1){
                c1++;
            }
            else if(num == ele2){
                c2++;
            }
            else if(c1 == 0){
                ele1 = num;
                c1 = 1;
            }
            else if(c2 == 0){
                ele2 = num;
                c2 = 1;
            }
            else{
                c1--;c2--;
            }
        }
        // ele1 and ele2 are the numbers which occurs greater than n/3 most times.
        c1 = 0;c2 = 0;
        for(auto num:nums){
            if(num == ele1){
                c1++;
            }
            else if(num == ele2){
                c2++;
            }
        }
        if(c1 > nums.size()/3){
            ans.push_back(ele1);
        }
        if(c2 > nums.size()/3){
            ans.push_back(ele2);
        }
        return ans;
    }
};