#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        // brute force nums1 ke elements ko ek ek karke le or nums2 ko greater elememt bana ta rah jis time nums1 ka elment abhi ke elemnt ke equal h us time return kar de
        // TC-O(N*M) SC -O(N)

        // int n = nums1.size();
        // int m = nums2.size();
        // vector<int>ans(n);
        // for(int i = 0; i < n; i++){
        //     int target = nums1[i]; // array1 ka target element
        //       stack<int>st; // stack for helping to find next greater
        //   for(int j = m-1; j>=0; j--) //next greater template
        //   {

        //      int curr = nums2[j];
        //      while(!st.empty() && curr >= st.top())
        //      {
        //         st.pop();
        //      }
        //      if(st.empty())
        //      { // check if target is equal to current and stack is empty means it its the greatest in array so set to -1
        //         if(target == curr) ans[i] = -1;
        //      }
        //      else
        //      {// means found a greatest element
        //         if(target == curr) ans[i] = st.top();
        //      }
        //      // push into stack
        //       st.push(nums2[j]);
        //   }
        // }
        //  return ans;

        // Optimize TC-O(N+M) SC -2 *O(M)
        // approach nums2 array ko next greater element bana dal by template
        // then har elemntka mapping kar de uske next greater ke sath
        // bs fir nums1 ke har elemnt ko map ki hui key se value nikal ans me dal
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int, int> mpp; // used to map element with its next grater
        stack<int> st;               // help to find next greater
        for (int i = m - 1; i >= 0; i--)
        {
            int curr = nums2[i];                    // current elemet
            while (!st.empty() && curr >= st.top()) // check for next greater if its not then stack is empty means it it is the greatest so map with -1 if greatest present then map witch stack top value
            {
                st.pop();
            }
            if (st.empty())
                mpp[curr] = -1;
            else
                mpp[curr] = st.top();
            st.push(curr); // pushing the values
        }

        vector<int> ans;       // used for ans
        for (auto &it : nums1) // making all nums1 elemnets to its greater
        {
            ans.push_back(mpp[it]);
        }
        return ans;
    }
};