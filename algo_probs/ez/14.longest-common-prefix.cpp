/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution
{

public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
        {
            return std::string("");
        }

        auto prefix = strs.front();
        auto next = ++strs.begin();
        while (next != strs.end())
        {
            auto bound = min(next->length(), prefix.length());
            prefix = prefix.substr(0, bound);

            for (auto i = 0; i < bound; ++i)
            {
                if (prefix.at(i) != next->at(i))
                {
                    prefix = prefix.substr(0, i);
                    break;
                }
            }
            ++next;
        }

        return prefix;
    }
};
// @lc code=end
