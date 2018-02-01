int searchInsert(int* nums, int numsSize, int target) {
    int high = numsSize-1, low = 0;
    
    // search O(logn) through the array
    while(low <= high) { // stop when number is not found
        int mid = (low+high)/2; // find middle index (same as low + (high/low)/2)
        int num = nums[mid]; // get middle number
        //printf("i = %d, num = %d\n", i, num);
        if(target == num) return mid; // found target
        else if(target < num) high = mid-1; // target is smaller (search lower half)
        else low = mid+1; // target is bigger (search upper half)
    }
    
    // target not found, return insert index
    return low; // always in low index
}
