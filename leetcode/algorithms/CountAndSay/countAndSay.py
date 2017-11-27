class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        seq = "1"
        if n is 1:
            return seq
        
        for i in range (n-1):
            count = 0
            num = seq[0]
            newSeq = ""
            for ch in seq:
                if ch is num:
                    count += 1
                else:
                    newSeq += str(count) + str(num)
                    count = 1
                    num = ch
            newSeq += str(count) + str(num)
            seq = newSeq
        
        return seq
