#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int power(char c)
    {
        if (c == '^')
            return 3;
        if (c == '*' || c == '/')
            return 2;
        if (c == '+' || c == '-')
            return 1;
        return 0;
    }

    string infixToPrefix(const string &s)
    {
        string str = s;

        reverse(str.begin(), str.end());

        int n = str.size();

        for (int i = 0; i < n; i++)
        {
            if (str[i] == '(')
                str[i] = ')';
            else if (str[i] == ')')
                str[i] = '(';
        }

        stack<char> st;
        string ans = "";

        for (int i = 0; i < n; i++)
        {
            char ch = str[i];

            if (isalnum(ch))
            {
                ans += ch;
            }
            else if (ch == '(')
            {
                st.push(ch);
            }
            else if (ch == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }

                if (!st.empty())
                    st.pop();
            }
            else
            {
                if (ch == '^')
                {
                    while (!st.empty() &&
                           power(st.top()) >= power(ch))
                    {
                        ans += st.top();
                        st.pop();
                    }
                }
                else
                {
                    while (!st.empty() &&
                           power(st.top()) > power(ch))
                    {
                        ans += st.top();
                        st.pop();
                    }
                }

                st.push(ch);
            }
        }

        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};