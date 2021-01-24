/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head)
        {
            ListNode *cur = head;

            while (cur)
            {
                if (head->val == val)
                {
                    head = head->next;
                    cur = head;
                }
                else
                {
                    if (cur->next)
                    {
                        if (cur->next->val == val)
                        {
                            cur->next = cur->next->next;
                            continue;
                        }
                    }

                    cur = cur->next;
                }
            }
        }

        return head;
    }
};
// @lc code=end
