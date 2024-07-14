/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node newHead(0);
        Node* tail = &newHead;
        Node* curr = head;
        unordered_map<Node*, Node*> map;
        // 复制链表的 next 指针
        // 遍历原链表
        while (curr) {
            Node* node = new Node(curr->val);
            tail->next = node;
            tail = tail->next;
            // 记录原链表节点和新链表节点的映射关系
            map[curr] = node;
            curr = curr->next;
        }
        // 复制链表的 random 指针
        curr = head;
        // 遍历原链表
        while (curr) {
            // 如果当前节点的 random 指针不为空
            if (curr->random) {
                // 通过 map 找到对应的新链表节点，然后赋值给新链表节点的 random 指针
                map[curr]->random = map[curr->random];
            }
            curr = curr->next;
        }
        return newHead.next;
    }
};
// @lc code=end

