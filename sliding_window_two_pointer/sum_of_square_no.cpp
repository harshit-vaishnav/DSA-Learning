#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool judgeSquareSum(int c)
    {

        // Brute Force
        //   if(c == 0 || c == 1) return true;
        //     long long left = 0;
        //     long long right= c / 2;
        //     while(left <= right)
        //     {
        //      if((left  * left) + (right * right) == c)
        //      {
        //          return true;
        //      }
        //       else if((left  * left) + (right * right) > c)
        //       {
        //          right--;
        //       }
        //       else left++;
        //     }
        //      return false;

        // Optimal

        for (long long a = 0; a * a <= c; a++)
        {
            int target = c - (a * a);

            int low = 0, high = sqrt(c);

            while (low <= high)
            {
                int mid = low + (high - low) / 2;

                if (mid * mid == target)
                    return true;
                else if (mid * mid > target)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }
        return false;
    }
};