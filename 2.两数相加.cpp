/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0); // 哨兵节点
        ListNode* tail = &dummy; // 当前节点指针
        int carry = 0; // 进位
        while(l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            sum = sum % 10;
            ListNode* node = new ListNode(sum); // 创建新节点
            tail->next = node; // 链接节点
            tail = tail->next; // 移动指针 
        }
        if (carry) {
            ListNode* node = new ListNode(carry);
            tail->next = node;
            tail = tail->next;
        }
        return dummy.next; // 返回合并后的链表头节点
    }
};
// @lc code=end

