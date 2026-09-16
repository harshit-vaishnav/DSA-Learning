#include <bits/stdc++.h>
using namespace std;
class MedianFinder
{
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxHeap.size() == 0)
        {
            maxHeap.push(num);
            return;
        }

        if (maxHeap.size() == minHeap.size())
        {
            if (num > maxHeap.top())
            {
                minHeap.push(num);
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            else
            {
                maxHeap.push(num);
            }
        }
        else
        {
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    double findMedian()
    {

        if (minHeap.size() == maxHeap.size())
        {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else
        {
            return maxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */