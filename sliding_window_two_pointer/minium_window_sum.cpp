#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();
        int minlen = INT_MAX;

        // for(int i = 0; i < n; i++)
        // {
        //      int sum = 0;
        //     for(int j = i; j < n; j++)
        //     {
        //          sum += nums[j];
        //         if(sum >= target)
        //         {
        //              minlen = min(minlen, j - i + 1);
        //             break;
        //         }
        //     }
        // }
        // return (minlen == INT_MAX) ? 0 : minlen;
         

         int l = 0, r = 0;
         int sum = 0;
         while(r < n)
        {
             sum += nums[r];

           while(sum >= target)
             {
                minlen = min(minlen , r - l + 1);
                sum -= nums[l];
                l++;
             }
              r++;
        }
      return (minlen == INT_MAX) ? 0 : minlen; 
    }
};