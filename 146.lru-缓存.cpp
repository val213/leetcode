/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
#include <unordered_map>
using namespace std;
class MyListNode {
public:
    int val, key;
    MyListNode* prev;
    MyListNode* next;
    MyListNode(int key, int val) : val(val),key(key), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, MyListNode*> mp;
    MyListNode *head, *tail;
    int cap, size;
public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = new MyListNode(-1, -1);
        tail = new MyListNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        // 如果key不存在，返回-1
        if (mp.find(key) == mp.end()) return -1;
        // 如果key存在，将节点移到链表头部
        MyListNode* node = mp[key];
        moveToHead(node);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if (mp.find(key) == mp.end()) {
            // 如果key不存在，插入新节点
            MyListNode* node = new MyListNode(key, value);
            mp[key] = node;
            // 将新节点插入到链表头部
            addToHead(node);
            size++;
            // 如果超过容量，删除尾部节点
            if (size > cap) {
                MyListNode* del = tail->prev;
                removeTail();
                mp.erase(del->key);
                delete del;
                size--;
            }
        } else {
            // 如果key存在，更新value
            mp[key]->val = value;
            // 将节点移到链表头部
            MyListNode* node = mp[key];
            moveToHead(node);
        }
    }

    void moveToHead(MyListNode* node) {
        node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;
        node->next = head->next;
        if (head->next) head->next->prev = node;
        head->next = node;
        node->prev = head;
    }
    void addToHead(MyListNode* node) {
        node->next = head->next;
        if (head->next) head->next->prev = node;
        head->next = node;
        node->prev = head;
    }
    void removeTail() {
        tail->prev->prev->next = tail;
        tail->prev = tail->prev->prev;
    }
};
    

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

