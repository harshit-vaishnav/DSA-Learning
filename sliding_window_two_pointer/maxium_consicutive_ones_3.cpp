#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        //   Question - kya ye question esa nahi hogya find longest subarray with at most k zeroes
        // agar esa hogya yani vhi sliding window pattern to chlo lagte h

        // Brute force  TC-O(N^2) SC - O(1)
        // int n = nums.size();
        // int MaxOnes = 0;
        // for(int i = 0; i < n; i++)
        // {
        //      int zeroes = 0;
        //      for(int j = i; j < n; j++)
        //      {
        //          if(nums[j] == 0) zeroes++;
        //          if(zeroes <= k) MaxOnes = max(MaxOnes,j - i + 1);
        //      }
        // }
        //  return MaxOnes;

        // Optimal Approach TC-O(N) SC - O(1)
        //  striver patten 2 optimal solution
        // approach  dek window bana le window ko tab tak expend kar jab tak zero ka cnt <=k agar isse jayda hua to window ko shrink kar but sath hi me tab tak jab tak ki vo kam ni ho jaye ya fir ham jab tak zeroes<=k lekar nhi aaye tab tak or kam bhi sirf 0 ko trim karna h to agar 0 h tab hi tirm karo ek point
        int n = nums.size();
        int MaxOnes = 0;
        int l = 0, r = 0;
        int zeroes = 0;
        while (r < n)
        {
            if (nums[r] == 0)
                zeroes++;
            if (zeroes > k)
            {
                if (nums[l] == 0)
                    zeroes--;
                l++;
            }
            if (zeroes <= k)
            {
                MaxOnes = max(MaxOnes, r - l + 1);
            }
            r++;
        }
        return MaxOnes;
    }
};