/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        // 快指针先走 n 步
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        // 如果快指针走到尾部，说明要删除的是头节点
        if (!fast) {
            return head->next;
        }
        // 快慢指针同时走，直到快指针走到尾部
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        // 删除倒数第 n 个节点
        slow->next = slow->next->next;
        return head;
    }
};
// @lc code=end

