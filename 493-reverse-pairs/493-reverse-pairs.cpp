class Solution {
public:

    int merge(vector<int> &nums,int left,int mid,int right){
        int cnt = 0;
        int i = left;
        int j = mid+1;
        int k = 0;
        vector<int> temp(right - left + 1);
        // cnt number of valid pairs.
        while(i <= mid && j <= right ){
            long long numj = nums[j];
            numj = 2 * numj;
            if(nums[i] > (numj)){
                cnt += mid - i + 1;
                j++;
            }
            else{
                i++;
            }
        }

        // update(merge) resultant array ->
        i = left;
        j = mid + 1;
        while(i <= mid && j <= right){
            if(nums[i] <= nums[j]){
                temp[k] = nums[i];
                i++;k++;
            }
            else{
                temp[k] = nums[j];
                j++;k++;
            }
        }

        while(i <= mid){
            temp[k] = nums[i];
            i++;k++;
        }
        while(j <= right){
            temp[k] = nums[j];
            j++;k++;
        }
        // Copy back the merged elements to original array.
        k = 0;
        for(int z = left;z <= right;z++){
            nums[z] = temp[k];
            k++;
        }
        return cnt;
    }

    int invertCount(vector<int> &nums,int left,int right){
        if(left == right){
            return 0;
        }

        int mid = (left + right) / 2;
        int a = invertCount(nums,left,mid);
        int b = invertCount(nums,mid+1,right);
        int aWithb = merge(nums,left,mid,right);

        return a + b + aWithb;
    }

    int reversePairs(vector<int>& nums) {
        return invertCount(nums,0,nums.size() - 1);
    }
};