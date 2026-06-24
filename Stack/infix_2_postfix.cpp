#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int power(char c)
    {
        if (c == '^')
            return 3;
        else if ((c == '*') || (c == '/'))
            return 2;
        else if ((c == '+') || (c == '-'))
            return 1;
        else
            return 0;
    }
    string infixToPostfix(string s)
    {
        //  TC-O(N) SC -O(N)
        // agar operand  h to ans me dalo agar operator h to stack me dalo
        // usme bhi high prroity ka hi stack me dalega agar low priority h to pop karo ans me add karo or bracket ke andar jite bhi opeator h sabko pop karo ans me dalo
        //  or last me stack se sare pop karo ans me dalo
        int n = s.size();
        stack<char> st;
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
            {
                ans += ch;
            }
            else if (ch == '(')
            {
                st.push(ch);
            }
            else if (ch == ')')
            {
                while (st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.empty() && power(st.top()) >= power(ch))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};