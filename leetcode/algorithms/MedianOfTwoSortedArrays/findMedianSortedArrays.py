class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        ind = -1
        combinedList = []
        median = 0.0
        
        while nums1 or nums2:
            if nums1 and nums2:
                if nums1[0] < nums2[0]:
                    combinedList.append(nums1[0])
                    nums1.pop(0)
                else:
                    combinedList.append(nums2[0])
                    nums2.pop(0)
            elif nums1:
                combinedList.append(nums1[0])
                nums1.pop(0)
            elif nums2:
                combinedList.append(nums2[0])
                nums2.pop(0)
            # recalculate median
            if len(combinedList)%2:
                ind += 1 # incerement on odd
                median = combinedList[ind]
            else:
                median = (combinedList[ind]+combinedList[ind+1])/2
                
        return median
