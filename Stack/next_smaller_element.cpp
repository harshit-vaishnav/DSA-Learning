
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextSmallerElements(const vector<int> &arr)
    {
        // Brute Force TC-O(N ^ 2) SC - O(N)
        //  vector<int>v = arr;
        //  int n = v.size();
        //     vector<int>ans(n,-1);
        //  for(int i = 0; i < n; i++)
        //  {
        //     for(int j = i + 1; j < n; j++)
        //     {
        //         if(v[j] < v[i])
        //         {
        //             ans[i] = v[j];
        //             break;
        //         }
        //     }
        //  }
        //   return ans;

        //   optimal appproach TC-O(2*N) SC - O(N)
        // use monotonic incerasing stack to finf next smaller
        vector<int> nums = arr;
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n);
        for (int j = n - 1; j >= 0; j--)
        {
            while (!st.empty() && st.top() >= nums[j])
            {
                st.pop();
            }
            if (st.empty())
                ans[j] = -1;
            else
                ans[j] = st.top();
            st.push(nums[j]);
        }
        return ans;
    }
};
