/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
// https://leetcode.com/problems/implement-strstr/solution/
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
        {
            return 0;
        }

        if (haystack.length() < needle.length())
        {
            return -1;
        }

        // navie search
        auto i = 0;
        auto cur = -1; // indicator
        while (i < haystack.length() - needle.length() + 1)
        {
            cur = i;
            for (auto j = 0; j < needle.length(); ++j)
            {
                if (haystack[cur++] != needle[j])
                {
                    cur = -1;
                    break;
                }
            }
            if (cur != -1)
            { // found match
                break;
            }

            ++i;
        }

        return cur != -1 ? i : cur;
    }
};
// @lc code=end
