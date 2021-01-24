/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindromeRec(ListNode **first, ListNode *second)
    {

        if (!second->next)
        {
            bool res = (*first)->val == second->val;
            (*first) = (*first)->next;
            return res;
        }

        bool res = isPalindromeRec(first, second->next) && (*first)->val == second->val;

        // std::cout << (*first)->val << ' ' << second->val << '\n';

        *first = (*first)->next;
        return res;
    }

    bool isPalindrome(ListNode *head)
    {
        if (!head)
        {
            return true;
        }

        ListNode *fast = head, *slow = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        //rec find
        ListNode *cur = head;
        return isPalindromeRec(&cur, slow);
    }
};
// @lc code=end
