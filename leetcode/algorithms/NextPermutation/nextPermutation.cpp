class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // TODO base cases
        if (nums.size() < 2)
            return;
        
        
        int ind = nums.size()-1; // index of first ascending pair
        
        // find first pair a[i] > a[i-1] from right
        for(int i=nums.size()-1; i>0; i--) {
            if(nums.at(i) > nums.at(i-1)) {
                ind = i-1;
                break;
            }
        }
        
        // Find next largest on the right side
        int next_largest_ind = ind+1;
        for(int i=ind+2; i<nums.size(); i++) {
            if (nums.at(i) > nums.at(ind)) {
                next_largest_ind = i;
            } else
                break; // found next largest value
        }
        
        // Swap nums
        if(next_largest_ind<nums.size()) { // check ascending pair exists
            int temp = nums.at(ind);
            nums[ind] = nums.at(next_largest_ind);
            nums[next_largest_ind] = temp;
            //nums.insert(nums.begin()+ind, nums.at(next_largest_ind));
            //nums.insert(nums.begin()+next_largest_ind, temp);
        }
        
        // Reverse right side order
        if (ind == nums.size()-1)
            sort(nums.begin(), nums.end());
        else
            sort(nums.begin()+ind+1, nums.end());
        /*for(int i=ind+1; i<nums.size(); i++) {
            
        }*/
        
    }
};
