class Solution {
public:
    int getBeg(vector<int>& nums, int target, int ind, int size) {
        //cout << "BEG: ind " << ind << " size " << size << endl;
        if (size == 1) {
            return (nums[ind] == target)? ind : nums.size();
        }
        
        int half = size/2;
        
        if (nums[ind+half] == target) { // go to the left even more
            int beg = getBeg(nums, target, ind, half);
            return (beg < ind+half)? beg : ind+half;
        }
        else // got back to the right
            return getBeg(nums, target, ind+half+(size%2), half);
    }
    
    int getEnd(vector<int>& nums, int target, int ind, int size) {
        //cout << "END: ind " << ind << " size " << size << endl;
        if (size == 1) {
            return (nums[ind] == target)? ind : 0;
        }
        
        int half = size/2;
        
        if (nums[ind+half] == target) { // go to the right even more
            int end = getEnd(nums, target, ind+half+(size%2), half);
            return (end > ind+half)? end : ind+half;
        }
        else // go back to the left
            return getEnd(nums, target, ind, half);
    }

	void findTarget(vector<int>& nums, int target, vector<int>& ans, int ind, int size) {
		//cout << "ind " << ind << " size " << size << endl;
        if (size == 1) {
			if(nums[ind] == target) { // single target found
                ans.push_back(ind);
                ans.push_back(ind);
                return;
			}
			else { // target not found
                ans.push_back(-1);
                ans.push_back(-1);
                return; 
            }
		}
		
		int half = size/2;
        
        if (target > nums[ind+half]) // search second half
            findTarget(nums, target, ans, ind+half+(size%2), half);
        else if (target < nums[ind+half]) // search first half
            findTarget(nums, target, ans, ind, half);
        else { // found target
            int beg = getBeg(nums, target, ind, half);
            ans.push_back((beg < ind+half)? beg : ind+half);
            int end = getEnd(nums, target, ind+half+(size%2), half);
            ans.push_back((end > ind+half)? end : ind+half);
        } 
	}

	vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return {-1, -1};
        }
        
        vector<int> ans;
        findTarget(nums, target, ans, 0, nums.size());
		
		return ans;
	}
};
