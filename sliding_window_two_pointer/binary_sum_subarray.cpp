#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int k)
    {

        // Brute Force TC-O(N^2) SC - O(1)
        // approach - sare subarray genrate kar lo then check kar lo kiska sum == k
        // agar h to uska cnt increase kar lo
        // int n = nums.size();
        // int SubarrayCnt = 0;

        // for(int i = 0; i < n; i++)
        // {
        //      int sum = 0;
        //      for(int j = i; j < n; j++)
        //      {
        //          sum += nums[j];
        //          if(sum == k) SubarrayCnt++;

        //          if(sum  > k) break;
        //      }
        // }
        // return SubarrayCnt;

        // Optimal Solution TC-(4*N) SC - O(1) Pattern - 3
        // appraoch question bol ra no of subarrays jiska sum == k ho yani numbe chaiye
        // to pattern -3 kyu na me sum <= k nikal lu fir us cnt ko sum <= k - 1 se substract
        // kar lu to mera ans aajyega yani pattrn 3 = 2 times of patten 2
        // but over here edge case what if k == 0 then
        // sum <= 0
        // sum <= -1 not possible so please if(k < 0) return 0;

        // step - 1 comppute cnt for which subarray sum <= k
        int l = 0, r = 0;
        int n = nums.size();
        int cntK = 0;
        int sum = 0;
        while (r < n)
        {
            sum += nums[r];

            while (sum > k)
            {
                sum -= nums[l];
                l++;
            }
            cntK += r - l + 1; // no of subarrays  == length
            r++;
        }
        //  step- 2 handle edge case
        if (k <= 0)
            return cntK;
        // step- 3 Compute cnt for which subarray sum < = k - 1;

        k = k - 1;    // please update k
        l = 0, r = 0; // update l and r also
        sum = 0;      // update sum also
        int cntK_1 = 0;
        while (r < n)
        {
            sum += nums[r];

            while (sum > k)
            {
                sum -= nums[l];
                l++;
            }
            cntK_1 += r - l + 1; // no of subarrays  == length
            r++;
        }

        // step - 4 return ans sum <= k - sum <= k - 1
        return cntK - cntK_1;
    }
};