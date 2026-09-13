#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findXSum(vector<int> &nums, int k, int x)
    {

        int n = nums.size();
        vector<int> ans;

        int l = 0, r = k - 1;

        while (r < n)
        {

            priority_queue<pair<int, int>> pq;
            unordered_map<int, int> mpp;

            for (int i = l; i <= r; i++)
            {
                mpp[nums[i]]++;
            }

            for (auto &it : mpp)
            {
                pq.push({it.second, it.first});
            }

            int sum = 0;
            int temp = x;
            while (temp != 0 && !pq.empty())
            {

                int first = pq.top().first;
                int second = pq.top().second;
                sum += (first * second);
                pq.pop();
                temp--;
            }
            ans.push_back(sum);
            l++;
            r++;
        }
        return ans;
    }
};