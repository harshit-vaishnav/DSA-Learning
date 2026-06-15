#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // approach- dek me jis element par hu muje usse piche wala next highst element chaiye ab
    // agar 1 element hi hua to vo hi higest hoga or uska span 1 hoga baki nexthighest element nikalne
    // ke liye stack ka use karo stack me element dalte raho hamesa check karo ki curr element se koi pahle bada
    // element aya h kya agar aaya h to vhi prevhighest h to uska span hoga = i-st.top
    // ab agar kisi elment ke liye koi next highest h hi nhi to pura stack empty ho jayga tab span i+1 ke qual hoga
    vector<int> StockSpan(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return {};
        vector<int> span(n); // created span array for return ans
        stack<int> st;       // created stack to find prevhighest store indx
        span[0] = 1;         // if array has 1 element then its a highest ele push it in stack as well as span
        st.push(0);
        for (int i = 1; i < n; i++)
        {

            int curr = nums[i];                           // cuurent element
            while (!st.empty() && curr >= nums[st.top()]) // find prev high
            {
                st.pop();
            }

            if (st.empty())
                span[i] = i + 1; // if there is no prevhighest means this is highest then span = i+1
            else
                span[i] = i - st.top(); // means there is a prevhighest element then calulate span = i - st.top
            st.push(i);                 // store indx of elemets
        }
        return span;
    }
};