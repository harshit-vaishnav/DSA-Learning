#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lastStoneWeight(vector<int> &nums)
    {

        // while(nums.size() > 1)
        // {
        //     sort(nums.begin(),nums.end());

        //     int last = nums.back();
        //     nums.pop_back();
        //     int secondLast = nums.back();
        //     nums.pop_back();

        //     if(last > secondLast) nums.push_back(last - secondLast);
        // }

        //  return (nums.size() == 1) ? nums[0] : 0;

        priority_queue<int> pq(nums.begin(), nums.end());

        while (pq.size() > 1)
        {
            int top = pq.top();
            pq.pop();

            int topSecond = pq.top();
            pq.pop();

            if (top > topSecond)
                pq.push(top - topSecond);
        }
        return (pq.empty()) ? 0 : pq.top();
    }
};