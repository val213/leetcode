/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        int pos = -1;
        if (!head || !head->next) return nullptr;
        // 快慢指针第一次相遇
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                pos = 0;
                break;
            }
        }
        // 用第三个指针在head处和slow指针一起走，相遇时找出入口
        if (pos == 0) {
            ListNode *p = head;
            while (p != slow) {
                p = p->next;
                slow = slow->next;
                pos++;
            }
        }
        return pos == -1 ? nullptr : slow;
    }
};
// @lc code=end

