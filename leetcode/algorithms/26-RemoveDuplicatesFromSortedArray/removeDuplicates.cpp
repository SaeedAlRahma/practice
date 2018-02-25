class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        int uniqueInd = 0; // 0th index must be unique
        for (int i = 1; i<nums.size(); i++) {
            if(nums[i] != nums[uniqueInd])
                nums[++uniqueInd] = nums[i];
        }
        
        return uniqueInd+1;
    }
};