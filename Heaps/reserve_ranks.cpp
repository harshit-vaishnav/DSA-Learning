#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &nums)
    {

        int n = nums.size();
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push({nums[i], i});
        }

        int rank = 1;

        vector<string> ans(n);

        while (!pq.empty())
        {
            int idx = pq.top().second;
            pq.pop();

            if (rank == 1)
            {
                ans[idx] = "Gold Medal";
            }
            else if (rank == 2)
            {
                ans[idx] = "Silver Medal";
            }
            else if (rank == 3)
            {
                ans[idx] = "Bronze Medal";
            }
            else
            {
                ans[idx] = to_string(rank);
            }
            rank++;
        }
        return ans;
    }
};