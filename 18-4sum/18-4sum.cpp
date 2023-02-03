class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;

        for(int i =0;i<n;i++){
            for(int j = i+1;j<n;j++){
                // long long a = target;
                // long long b = nums[i];
                // long long c = nums[j];
                // long long target2 = a - b - c;
                long long target2 = 1LL*target - 1LL*nums[i] - 1LL*nums[j];
                int front = j + 1;
                int back = n - 1;
                while(front < back){
                    
                    if(nums[front] + nums[back] < target2){
                        front++;
                    } 
                    else if(nums[front] + nums[back] > target2){
                        back--;
                    }
                    else{
                        // Quad is resulting vector.
                        vector<int> quad(4,0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[front];
                        quad[3] = nums[back];
                        res.push_back(quad);

                        while(front < back && nums[front] == quad[2]){
                            front++;
                        }
                        while(front < back && nums[back] == quad[3]){
                            back--;
                        }
                    }
                }

                // Now front > back ->
                while(j+1 < n && nums[j] == nums[j+1]){
                    j++;
                }
            }
            while(i+1 < n && nums[i] == nums[i+1]){
                i++;
            }
        }
        return res;
    }
};