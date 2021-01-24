/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }

        if (!l2) {
            return l1;
        }

        // dummy head
        auto dummy = ListNode();
        auto *curr = &dummy;

        // dispatch and attach to dummy
        while(l1 != nullptr && l2 != nullptr) {
            // cout << l1->val << "," << l2->val << '\n';
            if(l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
                curr = curr->next;
                curr->next = nullptr;
            } else {
                curr->next = l2;
                l2 = l2->next;
                curr = curr->next;
                curr->next = nullptr;
            }
        }
        
        // sort out the rest
        if (l1) {
            curr->next = l1;
        } 

        if (l2) {
            curr->next = l2;
        }

        return dummy.next;
    }
};
// @lc code=end

