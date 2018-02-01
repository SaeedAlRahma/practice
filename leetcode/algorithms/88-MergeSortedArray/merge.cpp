class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0) 
            return;
        
        if(m == 0) {
            nums1 = nums2;
            return;
        }
            
        vector<int> nums;
        for(int i=0; i<m; i++)
            nums.push_back(nums1[i]);
        
        nums1.clear();
        
        int i=0, j=0;
        while(i<m || j<n) {
            if(i>m-1) {
                nums1.push_back(nums2[j++]);
            }
            else if(j>n-1) {
                nums1.push_back(nums[i++]);
            }
            else {
                if(nums[i]<nums2[j]) {
                    nums1.push_back(nums[i++]);
                }
                else {
                    nums1.push_back(nums2[j++]);
                }
            }            
        }
    }
};
