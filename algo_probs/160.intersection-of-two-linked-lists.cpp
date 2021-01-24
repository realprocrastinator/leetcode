/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
        {
            return nullptr;
        }

        ListNode *curA = headA, *curB = headB;
        bool chA = false, chB = false;

        while (true)
        {

            if (!curB && !curA)
            {
                if (chA == chB)
                {
                    break;
                }
            }

            if (!curB->next && !chB)
            {
                chB = !chB;
                curB = headA;
            }

            if (!curA->next && !chA)
            {
                chA = !chA;
                curA = headB;
            }

            std::cout << curA->val << " " << curB->val << '\n';
            if (curA == curB && (chA == chB))
            {
                break;
            }

            curA = curA->next;
            curB = curB->next;
        }

        return curA == curB ? curA : nullptr;
    }
};
// @lc code=end
