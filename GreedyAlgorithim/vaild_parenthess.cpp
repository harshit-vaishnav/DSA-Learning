#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        // TC-O(N) SC-O(N)
        // approach use stack to store only open parenthess if any close bracket come pop with along its pair
        // imporantat edge case if ] string start with close bracket and if conditon not statisy then go to
        // the else then you check st.top but stack is emptyso we need to return false
        int n = s.size();
        if (n == 1)
            return false;
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else
            {
                if (st.empty())
                    return false;
                if (st.top() == '(' && s[i] == ')')
                    st.pop();
                else if (st.top() == '[' && s[i] == ']')
                    st.pop();
                else if (st.top() == '{' && s[i] == '}')
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};