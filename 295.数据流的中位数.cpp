/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;
class MedianFinder {
private:
    priority_queue<int> maxHeap; // 大顶堆，存储较小的一半元素
    priority_queue<int, vector<int>, greater<int>> minHeap; // 小顶堆，存储较大的一半元素
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        // 如果大顶堆为空或者当前元素小于等于大顶堆堆顶元素，则将当前元素插入大顶堆
        // 否则将当前元素插入小顶堆
        // 调整两个堆的大小，确保大顶堆的大小比小顶堆的大小大1或相等
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        } else {
            minHeap.push(num);
            if (minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }
    
    double findMedian() {
        // 如果两个堆的大小相等，则中位数为两个堆顶元素的平均值
        // 否则中位数为大顶堆的堆顶元素
        return maxHeap.size() == minHeap.size() ? (maxHeap.top() + minHeap.top()) / 2.0 : maxHeap.top();

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

