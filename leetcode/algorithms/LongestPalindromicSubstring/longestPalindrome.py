class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        
        def expandAroundCenter(s, left, right):
            # return the length of the palindrome around the center given
            l = left
            r = right
            while l>=0 and r<len(s) and s[l] == s[r]:
                l -= 1
                r += 1
            return r - l - 1
        
        start = 0
        end = 0
        for i in range(len(s)):
            len1 = expandAroundCenter(s, i, i)
            len2 = expandAroundCenter(s, i, i+1)
            length = max(len1, len2)
            if length > (end-start):
                start = i - (length-1)/2
                end = i + (length/2) + 1
                
        return s[start:end]
