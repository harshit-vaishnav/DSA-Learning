#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string prefixToPostfix(const string &s)
    {
        string str = s;
        int n = str.size();
        stack<string> st;
        for (int i = n - 1; i >= 0; i--)
        {
            char ch = s[i];
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
            {
                st.push(string(1, ch));
            }
            else
            {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                string ans = t1 + t2 + ch;
                st.push(ans);
            }
        }
        return st.top();
    }
};