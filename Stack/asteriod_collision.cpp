#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // size abs value of arr[i]
    //  + right dirxn
    // - left dirxn
    // same speed
    // opsite direction will collegin + to -
    // absarr[j] < absarr[i] arr[j] will distrory
    // absarr[j]=absarr[i] both will explorode
    // find out the state of the asteriods
    //  when is takkar happen
    //   jab pahle walaa arr[i] -> and arr[i - 1]
    //  moves to the left yani fist postive and second negative
    vector<int> asteroidCollision(vector<int> &nums)
    {
        stack<int> st;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            //   pakka collision hoga
            while (!st.empty() && (st.top() > 0 && nums[i] < 0))
            {
                int sum = st.top() + nums[i];
                if (sum < 0)
                {
                    st.pop();
                }
                else if (sum > 0)
                {
                    nums[i] = 0;
                }
                else
                {
                    st.pop();
                    nums[i] = 0;
                }
            }
            if (nums[i] != 0)
                st.push(nums[i]);
        }
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};