#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  long long mod = 1e9 + 7;
  vector<int> NextSmallerLeft(vector<int> nums)
  {
     int n = nums.size();
     vector<int>nsl(n);
     stack<int>st;
     for(int i = 0; i < n; i++)
     {
          while(!st.empty() && nums[st.top()] > nums[i])
         {
             st.pop();
         }
         if(st.empty())
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
     vector<int>nsr(n);
     stack<int>st;
 for(int i = n - 1; i >= 0; i--)
     {
          while(!st.empty() && nums[st.top()] >= nums[i])
         {
             st.pop();
         }
         if(st.empty())
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

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0;
        vector<int>nsl = NextSmallerLeft(arr);
        vector<int>nsr = NextSmallerRight(arr);
        for(int i = 0; i < n; i++)
        {
             int leftcnt = i - nsl[i];
             int rightcnt = nsr[i] - i;
             long long subarr = (1LL * leftcnt * rightcnt);
             ans = (ans + (subarr * arr[i] % mod)) % mod;    
        }
         return ans;
    }
};