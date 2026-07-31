#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        // Brute Force TC-O(N * K) SC - O(1)
        // Genrate all subarray if subarry length is k then compute avg and comapre with maxavg subarray length formula j - i + 1

        //  double MaxAvg = INT_MIN;
        //   int n = nums.size();
        // for(int i = 0; i < n; i++)
        // {
        //      int sum = 0;
        //      for(int j = i; j < n; j++)
        //      {
        //          sum += nums[j];
        //           if(j - i + 1 == k) // subarray length == k then compute avg
        //           {
        //                 MaxAvg = max(MaxAvg,(double)sum / k);
        //                 break;
        //           }
        //      }
        // }
        //  return MaxAvg;

        //  optimal solution sliding window pattern 1 TC-o(N) SC-o(1)
        // approach-jab bhi fixed window ho jese yaaha 4 length ki fix h window
        // then pattern 1 lagaao jisme ham left wale ko hata the h right vale ko add karte h
        int n = nums.size();
        double MaxAvg = INT_MIN;
        int l = 0, r = k - 1;
        int sum = 0;

        // precomputation of sum of length k

        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }

        // pahle se maxavg nikal liya kyunki window size ornums.size() equal hogye to
        MaxAvg = (double)(sum * 1.000 / k);

        // now hatao add karo
        while (r < n - 1)
        {
            sum = sum - nums[l];                    // hatya
            l++;                                    // shrink
            r++;                                    // expend
            sum = sum + nums[r];                    // add
            double avg = (double)(sum * 1.000 / k); // compute
            MaxAvg = max(avg, MaxAvg);              // comapre with maxavg
        }
        return MaxAvg;
    }
};