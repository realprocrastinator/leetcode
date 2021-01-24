/*
 * @lc app=leetcode id=1290 lang=cpp
 *
 * [1290] Convert Binary Number in a Linked List to Integer
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    int sumRec(ListNode *head, int *depth)
    {
        if (!head->next)
        {
            return head->val << (*depth)++;
        }

        return sumRec(head->next, depth) + (head->val << (*depth)++);
    }

    int getDecimalValue(ListNode *head)
    {
        if (!head)
        {
            return 0;
        }

        int depth = 0;

        return sumRec(head, &depth);
    }
};
// @lc code=end
