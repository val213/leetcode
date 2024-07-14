/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *prev = &dummy, *end = &dummy;

    while (end->next != nullptr) {
        // 尝试向前移动end指针k次
        for (int i = 0; i < k && end != nullptr; i++) end = end->next;
        // 如果end为nullptr，说明剩余节点不足k个，不需要翻转，直接跳出循环
        if (end == nullptr) break;

        // 保存当前组的下一组的头节点
        ListNode* nextGroup = end->next;
        // 断开当前组与下一组的连接，以便独立翻转当前组
        end->next = nullptr;
        // 保存当前组的头节点
        ListNode* start = prev->next;
        // 翻转当前组
        prev->next = reverse(start);
        // 翻转后，start成为了当前组的尾节点，连接到下一组的头节点
        start->next = nextGroup;

        // 重置prev和end指针，准备处理下一组
        prev = start;
        end = start;
    }
    return dummy.next;
    }
    // 实现链表翻转的辅助函数
    ListNode* reverse(ListNode* head) {
        ListNode *prev = nullptr, *curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }
};
// @lc code=end

