#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPossibleDivide(vector<int> &nums, int k)
    {
        int n = nums.size();

        // unordered_map<int,int>mpp; // element -> freq

        // for(auto &it : nums)
        // {
        //      mpp[it]++;
        // }

        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; // element -> freq

        // for(auto &it : mpp)
        // {
        //    pq.push({it.first,it.second});
        // }

        // while(!pq.empty())
        // {
        //      int prevE = 0;
        //      int t = k;
        //      vector<pair<int,int>>temp;

        //      while(t != 0)
        //      {
        //        int ele = pq.top().first;
        //        int freq = pq.top().second;
        //         pq.pop();
        //         freq--;
        //         temp.push_back({ele,freq});

        //         if((k == t) || (ele - prevE == 1))
        //         {
        //             t--;
        //             prevE = ele;
        //         }
        //         else return false;
        //      }

        //      for(auto &it : temp)
        //      {
        //          int ele = it.first;
        //          int freq = it.second;
        //          if(ele > 0 && freq > 0) pq.push({ele,freq});
        //      }

        // }
        // return true;

        if (n % k != 0)
            return false;

        map<int, int> mpp;

        for (auto &it : nums)
        {
            mpp[it]++;
        }

        while (!mpp.empty())
        {
            int curr = mpp.begin()->first;

            for (int i = 0; i < k; i++)
            {
                if (mpp[curr + i] == 0)
                    return false;
                mpp[curr + i]--;

                if (mpp[curr + i] == 0)
                    mpp.erase(curr + i);
            }
        }
        return true;
    }
};