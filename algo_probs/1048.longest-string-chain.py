#
# @lc app=leetcode id=1048 lang=python3
#
# [1048] Longest String Chain
#

# @lc code=start
class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        from itertools import combinations
        # sort the words list by len of word
        words = sorted(words,key=len)
        #map the word with its longest chain
        w_dict = {}
        for w in words:
            w_dict[w] = 1
        
        result = 1
        for w in words:
            l = len(w)
            # we check the combination of the subset string of the words
            for l in combinations(w,l-1):
                c = "".join(e for e in l)
                if c in w_dict:
                    
                    # we found an pred
                    w_dict[w] = max(w_dict[w],w_dict[c] + 1)
            result = max(result,w_dict[w])
        return result
            
        
# @lc code=end

