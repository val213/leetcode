/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        // 归并排序（递归）
        if (!head || !head->next) return head;
        // 快慢指针找到链表中点
        ListNode* slow = head;
        // 注意这里fast指针从head->next开始
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 断开链表，tmp保存右链表头节点
        ListNode* tmp = slow->next;
        slow->next = nullptr;
        // 递归排序左右链表
        ListNode* left = sortList(head);
        ListNode* right = sortList(tmp);
        // 合并两个有序链表
        ListNode* h = new ListNode(0);
        ListNode* res = h;
        while (left && right) {
            if (left->val < right->val) {
                h->next = left;
                left = left->next;
            } else {
                h->next = right;
                right = right->next;
            }
            h = h->next;
        }
        // 将剩余链表连接到合并链表
        h->next = left ? left : right;
        // 返回合并链表
        return res->next;
    }
};
// @lc code=end

