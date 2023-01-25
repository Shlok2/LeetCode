class Solution {
public:
    
    //     MERGE SORT -> 
    //
    //     int i = m-1;
    //     int j = n-1;
    //     int k = m+n-1;
    //     while(i>=0 && j>=0){
    //         if(nums1[i] >= nums2[j]){
    //             nums1[k] = nums1[i];
    //             i--;
    //             k--;
    //         }
    //         else{
    //             nums1[k] = nums2[j];
    //             j--;
    //             k--;
    //         }
    //     }
    //     while(i>=0){
    //         nums1[k] = nums1[i];
    //         k--;i--;
    //     }
    //     while(j>=0){
    //         nums1[k] = nums2[j];
    //         k--;j--;
    //     }
    
    //    GAP ALGO (Remember this algo)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        
        // Combine both arrays in nums1.
        for(int i = 0;i<n;i++){
            nums1[m+i] = nums2[i];
        }
        
        // Eg if nums1 have 7 elements then gap = 4.
        int gap = ceil((float)(m+n)/2);
        
        while(gap > 0){
            int i = 0;
            int j  = i + gap;
            while(j < (m+n)){
                
                if(nums1[i] > nums1[j]){
                    swap(nums1[i],nums1[j]);
                }
                i++;
                j++;
            }
            
            if(gap == 1){
                // gap = 0;
                break;
            }
            else{
                gap = ceil((float)gap/2);
            }
            
        }
    }
};