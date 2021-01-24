/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        // if (nums.empty() || (nums.size() == 1 && nums[0] == val))
        // {
        //     return 0;
        // }
        auto i = 0;
        auto j = i;

        for (; j < nums.size(); ++j)
        {
            if (nums[j] != val)
            {
                nums[i++] = nums[j];
            }
        }

        return i;
    }
};
// @lc code=end
