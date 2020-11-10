#
# @lc app=leetcode id=3 lang=python3
#
# [3] Longest Substring Without Repeating Characters
#

# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i = 0
        j = 0
        charset = set()
        maxlen = 0
        while i < len(s) and j < len(s):
            if (s[j] not in charset):
                charset.add(s[j])
                if max(len(charset),j-i) > maxlen:
                    maxlen = max(len(charset),j-i)
                j += 1
            else:
                cahrset = charset.remove(s[i])
                i += 1
        return maxlen
        
# @lc code=end

