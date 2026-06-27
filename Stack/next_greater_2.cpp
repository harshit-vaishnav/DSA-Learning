#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        //    int n = nums.size();
        //     vector<int>ans(n,-1);
        // TC-O(N^2) SC - O(N)
        // Brute Force
        // har ek element ke liye uski next index se lekar uski ik index kam tak taverse kar lo
        // ciruclar array me traversing n + i index tak hoti h
        //    for(int i = 0; i < n; i++)
        //    {
        //      for(int j = i + 1; j < n + i; j++)
        //      {
        //          int idx = j % n;
        //          if(nums[idx] > nums[i])
        //          {
        //               ans[i] = nums[idx];
        //               break;
        //          }
        //      }
        //    }
        //     return ans;

        //  Optimal approach TC-(4*N) SC - O(2*N) + O(N)
        //  array ko hypothetcaillly double kar do fir us hypothatic index se loop chlau or stack me monotonic deceressing oder lagao
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for (int j = 2 * n - 1; j >= 0; j--)
        {
            int idx = j % n;
            while (!st.empty() && nums[idx] >= st.top())
            {
                st.pop();
            }
            if (j < n)
            {
                ans[idx] = st.empty() ? -1 : st.top();
            }
            st.push(nums[idx]);
        }
        return ans;
    }
};