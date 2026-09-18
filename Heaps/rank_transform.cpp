#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &nums)
    {

        //  sorting + hashmap

        int n = nums.size();

        // vector<int>temp(nums.begin(),nums.end());

        // sort(temp.begin(),temp.end());

        // unordered_map<int,int>mpp;

        // int cnt = 1;

        // for(int i = 0; i < n; i++)
        // {
        //      if(mpp.find(temp[i]) == mpp.end())
        //      {
        //          mpp[temp[i]] = cnt;
        //          cnt++;
        //      }
        // }

        //  vector<int>ans;
        // for(int i = 0; i < n; i++)
        // {
        //      ans.push_back(mpp[nums[i]]);
        // }

        // return ans;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans(n);
        int rank = 1;

        for (int i = 0; i < n; i++)
        {
            pq.push({nums[i], i});
        }

        if (pq.size() == 0)
            return {};

        int prevval = pq.top().first;
        int i = pq.top().second;
        ans[i] = rank;
        pq.pop();

        while (!pq.empty())
        {
            int val = pq.top().first;
            int i = pq.top().second;
            pq.pop();

            if (val != prevval)
            {
                rank++;
                ans[i] = rank;
            }
            else
            {
                ans[i] = rank;
            }
            prevval = val;
        }

        return ans;
    }
};