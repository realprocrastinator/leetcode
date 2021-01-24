/*
 * @lc app=leetcode id=1317 lang=cpp
 *
 * [1317] Convert Integer to the Sum of Two No-Zero Integers
 */

// @lc code=start
class Solution
{
public:
    bool has_zero(int n)
    {
        if (n == 0)
            return false;

        while (n > 0)
        {
            if (n % 10 == 0)
            {
                return true;
            }
            n /= 10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n)
    {
        vector<int> res;
        for (auto i = 1; i <= n / 2; ++i)
        {
            auto b = n - i;
            if (!has_zero(i) && !has_zero(b))
            {
                res.push_back(i);
                res.push_back(b);
                return res;
            }
        }
        return res;
    }
};
// @lc code=end
