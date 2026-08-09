#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {

        // Brute Force TC-O(N^2) SC-O(1)
        // Approach- find all subarray and maintain a count var for tracking odd numbers
        // if oddnumbers cnt is == k then increase the ans if it is greate then just break
        // int n = nums.size();

        // int ans = 0;

        // for(int i = 0; i < n; i++)
        // {
        //     int cnt = 0;
        //     for(int j = i; j < n; j++)
        //     {
        //          if(nums[j] % 2 != 0) cnt++;
        //          if(cnt == k ) ans++;
        //          if(cnt > k) break;
        //     }
        // }
        //   return ans;

        // Optimal Solution TC-(4N) SC-O(1)

        // approach-pattern 4 if I need number of subarays then basic logic oddcnt <= k
        // and oddcnt <= k - 1 subtract both and get your ans

        // step-1 Find subarrays where oddcnt <= k  by appling pattern 2

        int n = nums.size();
        int l = 0, r = 0;
        int cnt = 0, ansK = 0;

        while (r < n)
        {
            if (nums[r] % 2 != 0)
                cnt++;
            while (cnt > k)
            {
                if (nums[l] % 2 != 0)
                    cnt--;
                l++;
            }

            ansK += r - l + 1; // subarrays is equal array size
            r++;
        }

        //  step - 2 now find subarrays where oddcnt <= k - 1 so update k to k - 1
        // note- in constraint you have k value is 1, so k - 1 be k == 0 then no need of edge case

        k = k - 1;
        l = 0, r = 0;
        cnt = 0;
        int ansK_1 = 0;
        while (r < n)
        {
            if (nums[r] % 2 != 0)
                cnt++;

            while (cnt > k)
            {
                if (nums[l] % 2 != 0)
                    cnt--;
                l++;
            }

            ansK_1 += r - l + 1;
            r++;
        }

        // step-3 return the ans that is odcnt <= k    -    oddcnt<= k - 1
        return ansK - ansK_1;
    }
};