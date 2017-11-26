# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        cur1 = l1
        cur2 = l2
        carryon = 0
        curSum = cur1.val + cur2.val + carryon
        retList = ListNode(curSum%10)
        carryon = curSum/10
        cur = retList
        
        while cur1.next or cur2.next:
            if cur1.next:
                cur1 = cur1.next
                x1 = cur1.val
            else:
                x1 = 0
            if cur2.next:
                cur2 = cur2.next
                x2 = cur2.val
            else:
                x2 = 0
                
            curSum = x1 + x2 + carryon
            cur.next = ListNode(curSum%10)
            carryon = curSum/10
            cur = cur.next
        """
        while cur1.next:
            cur1 = cur1.next
            curSum = cur1.val + carryon
            cur.next = ListNode(curSum%10)
            cur = cur.next
            if curSum > 9:
                carryon = 1
            else:
                carryon = 0
        while cur2.next:
            cur2 = cur2.next
            curSum = cur2.val + carryon
            cur.next = ListNode(curSum%10)
            cur = cur.next
            if curSum > 9:
                carryon = 1
            else:
                carryon = 0
        """
        if carryon:
            cur.next = ListNode(carryon)
            cur = cur.next
        
            
        return retList
