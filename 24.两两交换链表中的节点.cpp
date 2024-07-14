/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0); // 创建一个哨兵节点
        dummy.next = head;
        ListNode* curr = &dummy; // curr指针指向哨兵节点，用于追踪当前处理的节点对的前一个节点

        while (curr->next && curr->next->next) {
            ListNode* first = curr->next; // 当前节点对的第一个节点
            ListNode* second = curr->next->next; // 当前节点对的第二个节点

            // 交换节点对
            first->next = second->next;
            second->next = first;
            curr->next = second;

            // 移动curr指针到下一个要处理的节点对的前一个节点
            curr = first;
        }
        return dummy.next; // 返回哨兵节点的下一个节点，即新的头节点
    }
};
// @lc code=end

