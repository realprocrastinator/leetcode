/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        auto stack = vector<char>();
        for (const auto p : s)
        {
            auto match = true;

            if (p == '(' || p == '{' || p == '[')
            {
                stack.push_back(p);
                continue;
            }

            if (p == ')')
            {
                if (!stack.empty())
                {

                    match = stack.back() == '(';
                }
                else
                {
                    cout << "lalal";
                    return false;
                }
            }

            if (p == '}')
            {
                if (!stack.empty())
                {
                    match = stack.back() == '{';
                }
                else
                {
                    return false;
                }
            }

            if (p == ']')
            {
                if (!stack.empty())
                {
                    match = stack.back() == '[';
                }
                else
                {
                    return false;
                }
            }

            if (!match)
            {
                return false;
            }
            else
            {
                stack.pop_back();
            }
        }

        return stack.empty();
    }
};
// @lc code=end
