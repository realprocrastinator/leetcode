/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    //     // rec
    //     ListNode* reverseListRec(ListNode *from, ListNode *cur){
    //         if (!cur->next) {
    //             cur->next = from;
    //             return cur;
    //         }

    //         ListNode* newhead = reverseListRec(cur, cur->next);
    //         cur->next = from;
    //         return newhead;
    //     }

    //     ListNode* reverseList(ListNode* head) {
    //         if (head) {
    //             ListNode * newhead = reverseListRec(nullptr, head);
    //             return newhead;
    //         }

    //         return head;

    //     }

    // iterative
    // using stack

    ListNode *reverseList(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }

        auto stack = std::vector<ListNode *>();

        while (head)
        {
            stack.push_back(head);
            head = head->next;
        }

        ListNode *newhead = stack.back();
        stack.pop_back();

        ListNode *cur = newhead;

        while (!stack.empty())
        {
            cur->next = stack.back();
            stack.pop_back();
            cur = cur->next;
        }

        cur->next = nullptr;
        return newhead;
    }
};
// @lc code=end
