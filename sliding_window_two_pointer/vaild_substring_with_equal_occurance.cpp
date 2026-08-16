#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countValidSubarrays(vector<int> &nums, int x)
    {

        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            long long sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                int last_digit = sum % 10;
                long long first = sum;
                while (first >= 10)
                {
                    first /= 10;
                }
                if (first == x && last_digit == x)
                    cnt++;
            }
        }
        return cnt;
    }
};