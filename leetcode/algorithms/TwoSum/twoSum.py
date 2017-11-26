class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        """
        # Time limit exceeded
        for i in range(len(nums)):
            for j in range(1,len(nums)-i):
                if nums[i]+nums[len(nums)-j]==target:
                    return [i, len(nums)-j]
                elif nums[i]+nums[len(nums)-j] < target:
                    break
        """
        
        nums_len = len(nums)
        
        if nums_len < 2:
            return False
        
        myDict = {}
        
        for i in range(nums_len):
            if nums[i] in myDict:
                return [myDict[nums[i]], i]
            else:
                myDict[target - nums[i]] = i
        
        return False
