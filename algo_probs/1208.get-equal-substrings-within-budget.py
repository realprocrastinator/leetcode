#
# @lc app=leetcode id=1208 lang=python3
#
# [1208] Get Equal Substrings Within Budget
#

# @lc code=start
class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        if not s or not t:
            return 0
        cost = []
        for i in range (len(s)):
            cost.append(abs(ord(s[i]) - ord(t[i])))
        
        l = 0
        r = 0
        c = cost[0]
        length = 0
        while r < len(s):
            if c <= maxCost:
                # inc the len, in case not contiguous we need to change the head
                length = max(length,r-l+1)
            else:
                # sliding the window
                c -= cost[l]
                l += 1
            
            # inc the cost of the next ele
            if r + 1 < len(s):
                c += cost[r+1]
            r += 1
        
        return length
# @lc code=end

