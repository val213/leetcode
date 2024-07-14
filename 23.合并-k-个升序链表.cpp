/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct cmp {
            bool operator() (ListNode* a, ListNode* b) {
                return a->val > b->val;
            }
        };
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        // 把所有链表的头节点放入优先队列
        for (auto list : lists) {
            if (list) pq.push(list);
        }
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (!pq.empty()) {
            // 取出最小节点放进合并链表
            ListNode* t = pq.top();
            pq.pop();
            cur->next = t;
            cur = cur->next;
            // 如果最小节点有后继节点，将后继节点放入优先队列
            if (t->next) pq.push(t->next);
        }
        return dummy->next;
    }
};
// @lc code=end

