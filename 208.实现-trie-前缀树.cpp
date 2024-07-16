/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
#include <unordered_map>
#include <string>
using namespace std;
class TrieNode{
public:
    // 是否是字符的结尾
    bool is_end_of_word;
    // 每个节点都有一个维护其子字符节点的哈希表
    unordered_map<char,TrieNode*> children;
    TrieNode(){
        is_end_of_word = false;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* Node = root; 
        for (char c : word){
            if (Node->children.find(c)==Node->children.end()){
                Node->children[c]=new TrieNode();
            }
            Node = Node->children[c];
        }
        Node->is_end_of_word = true;
    }
    
    bool search(string word) {
        TrieNode* Node = root;
        for (char c : word){
            if (Node->children.find(c)==Node->children.end()){
                return false;
            }
            Node = Node->children[c];
        }
        return Node->is_end_of_word;
    }
    
    bool startsWith(string prefix) {
        TrieNode* Node = root;
        for (char c : prefix){
            if (Node->children.find(c)==Node->children.end()){
                return false;
            }
            Node = Node->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

