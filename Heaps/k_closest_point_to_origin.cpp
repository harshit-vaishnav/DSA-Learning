#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &nums, int k)
    {

        int n = nums.size();
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        for (int i = 0; i < n; i++)
        {
            int x = nums[i][0];
            int y = nums[i][1];

            long long distance = (x * x) + (y * y);
            pq.push({distance, i});
        }

        vector<vector<int>> ans;
        while (k != 0)
        {
            int idx = pq.top().second;
            pq.pop();
            ans.push_back(nums[idx]);
            k--;
        }
        return ans;
    }
};