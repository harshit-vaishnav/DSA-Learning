#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {

        int n = nums.size();

        //  Brute Force  Genrate all the subarray we need unique or
        // different k size elements in subarayso we use set then check
        // if set size is == k then ans++ if any case set size is greater
        // then our k break

        // int ans = 0;
        // for(int i = 0; i < n; i++)
        // {
        //      unordered_set<int>st;
        //    for(int j = i; j < n; j++)
        //    {
        //        st.insert(nums[j]);
        //        if(st.size() == k)
        //        {
        //          ans++;
        //        }
        //        if(st.size() > k) break;
        //    }
        // }
        //  return ans;

        // Optimal TC- O(4N) SC - O(2N)

        // approach  pattern 4  first find subarray  cnt where at most <=k
        // and then find <= k - 1 and substract them

        unordered_map<int, int> mpp;
        int ans = 0;
        int l = 0, r = 0;
        while (r < n)
        {
            mpp[nums[r]]++;
            while (mpp.size() > k)
            {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0)
                    mpp.erase(nums[l]);
                l++;
            }
            ans += (r - l + 1);
            r++;
        }

        mpp.clear();
        k = k - 1;
        l = 0, r = 0;
        int ans2 = 0;
        while (r < n)
        {
            mpp[nums[r]]++;
            while (mpp.size() > k)
            {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0)
                    mpp.erase(nums[l]);
                l++;
            }
            ans2 += (r - l + 1);
            r++;
        }
        return ans - ans2;
    }
};