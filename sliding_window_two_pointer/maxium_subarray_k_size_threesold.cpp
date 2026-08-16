#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numOfSubarrays(vector<int> &nums, int k, int t)
    {

        //   int n = nums.size();
        //   int l = 0, r = k - 1;
        //   int sum = 0, ans = 0;
        //  for(int i = 0; i <= k - 1; i++)
        //  {
        //       sum += nums[i];
        //  }
        //     float avg = sum / k;
        //     if(avg >= t) ans++;
        //   while(r < n - 1)
        //   {
        //      sum -= nums[l];
        //      l++;
        //      r++;
        //      sum += nums[r];
        //      float avg = sum / k;
        //      if(avg >= t) ans++;
        //   }
        //    return ans;

        int n = nums.size();
        int l = 0, r = 0;
        int sum = 0, ans = 0;
        while (r < n)
        {
            sum += nums[r];

            if ((r - l + 1) == k)
            {
                float avg = sum / k;

                if (avg >= t)
                {
                    ans++;
                }
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return ans;
    }
};