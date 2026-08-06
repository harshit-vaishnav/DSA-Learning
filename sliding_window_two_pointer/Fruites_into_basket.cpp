#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int totalFruit(vector<int> &nums)
    {
        int n = nums.size();
        // Question Maxium subarray with at most 2 type of basket

        // Brute Force Genrate all subarray and then check of basket eqal 2 use set
        // TC-O(N^2) SC - O(3)
        // int MaxLen = 0;
        // for(int i = 0; i < n; i++)
        // {
        //      unordered_set<int>st;
        //      for(int j = i; j < n; j++)
        //      {
        //           st.insert(nums[j]);
        //         if(st.size() <= 2)
        //         {
        //              MaxLen = max(MaxLen,j - i + 1);
        //         }
        //         else break;
        //      }
        // }
        // return MaxLen;

        //  Optimal sol  TC-O(N) SC - O(3)

        int MaxLen = 0;
        int l = 0, r = 0;
        unordered_map<int, int> mpp;
        while (r < n)
        {
            mpp[nums[r]]++;

            if (mpp.size() > 2)
            {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0)
                    mpp.erase(nums[l]);
                l++;
            }

            MaxLen = max(MaxLen, r - l + 1);
            r++;
        }
        return MaxLen;
    }
};