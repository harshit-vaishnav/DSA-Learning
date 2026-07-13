#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> NextSmallerLeft(vector<int> nums)
    {
        int n = nums.size();
        vector<int> nsl(n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] > nums[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                nsl[i] = -1;
            }
            else
            {
                nsl[i] = st.top();
            }
            st.push(i);
        }
        return nsl;
    }
    vector<int> NextSmallerRight(vector<int> nums)
    {
        int n = nums.size();
        vector<int> nsr(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                nsr[i] = n;
            }
            else
            {
                nsr[i] = st.top();
            }
            st.push(i);
        }
        return nsr;
    }
    long long sumSubarrayMins(vector<int> arr)
    {
        int n = arr.size();
        long long ans = 0;
        vector<int> nsl = NextSmallerLeft(arr);
        vector<int> nsr = NextSmallerRight(arr);
        for (int i = 0; i < n; i++)
        {
            int leftcnt = i - nsl[i];
            int rightcnt = nsr[i] - i;
            long long subarr = (1LL * leftcnt * rightcnt);
            ans = (ans + (subarr * arr[i]));
        }
        return ans;
    }
    vector<int> findngl(vector<int> nums)
    {
        int n = nums.size();
        stack<int> st;
        vector<int> ngl(n);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[i] > nums[st.top()])
            {
                st.pop();
            }
            if (st.empty())
            {
                ngl[i] = -1;
            }
            else
            {
                ngl[i] = st.top();
            }
            st.push(i);
        }
        return ngl;
    }
    vector<int> findngr(vector<int> nums)
    {
        int n = nums.size();
        stack<int> st;
        vector<int> ngr(n);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[i] >= nums[st.top()])
            {
                st.pop();
            }
            if (st.empty())
            {
                ngr[i] = n;
            }
            else
            {
                ngr[i] = st.top();
            }
            st.push(i);
        }
        return ngr;
    }
    long long sumSubarrayMaxs(vector<int> arr)
    {
        long long ans = 0;
        int n = arr.size();
        vector<int> ngr = findngr(arr);
        vector<int> ngl = findngl(arr);
        for (int i = 0; i < n; i++)
        {
            int leftcnt = i - ngl[i];
            int rightcnt = ngr[i] - i;
            long long subarray = leftcnt * rightcnt * 1LL;
            ans += subarray * arr[i];
        }
        return ans;
    }
    long long subArrayRanges(vector<int> &nums)
    {
        // Brute force sare subarray genrate kar de fir un subarray me maxium and minium element ka track rakta rah
        //  TC-O(N^2) SC - O(1)
        //  long long sum = 0;
        //  for(int i = 0; i < n; i++)
        //  {
        //      int maxi = INT_MIN;
        //      int mini = INT_MAX;
        //      // 1 1
        //     for(int j = i; j < n; j++)
        //     {
        //          maxi = max(nums[j],maxi);
        //          mini = min(nums[j],mini);
        //          long long Range = maxi - mini;
        //         sum += Range;
        //     }
        //  }
        //   return sum;
        // Optimal approacch TC-o(N) SC -O(N)
        // appraoch dek saresubarray genrate karke maxium minium nikalne se acha
        // har element kitne subarray me maxium aya or har element kitne subarray meminium aaya unka cnt nikal du or ese hi pure subarray me sabse maxium element ka sum or ese hi pure subarray me sabse minium element ka sum nikal do or dono ko minus kar do to my job will be done to hamne sumsubarrayminium to nikala hua h yad kar bs ab subarray maxium nikal lu or kya ab subarray maxium ke liye muje next greater element chaiye hoga vo karke nikal du ans done
        return (sumSubarrayMaxs(nums) - sumSubarrayMins(nums));
    }
};