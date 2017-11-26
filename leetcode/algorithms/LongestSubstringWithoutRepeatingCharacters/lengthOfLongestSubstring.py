from sets import Set

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        if len(s) < 1:
            return 0
        elif len(s) < 2:
            return 1
        
        count = 0
        maxCount = 0
        charSet = Set([])
        charSet.clear()
        curS = s
        
        # find first occurence and start from there
        for ch in s:
            if ch in charSet:
                ind = curS.find(ch)
                count -= ind
                for i in range(ind):
                    charSet.remove(curS[i])
                curS = curS[ind+1:]
            else:
                charSet.add(ch)
                count += 1
                if count > maxCount:
                    maxCount = count
                
        
        
        return maxCount
