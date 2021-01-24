/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        auto i = 0;
        auto j = i + 1;
        for (; j < nums.size(); ++j)
        {
            if (nums[i] < nums[j])
            {
                nums[++i] = nums[j];
            }
        }

        return i + 1; //length = index + 1
    }
};
// @lc code=end
