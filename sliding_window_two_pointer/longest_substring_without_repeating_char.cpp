#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // int n = s.size();
        // int MaxLen = 0;
        // for(int i = 0; i < n; i++)
        // {
        //     int cnt = 0;
        //     unordered_set<char>st;
        //     for(int  j = i; j < n; j++)
        //     {
        //          if(st.count(s[j])) break;
        //             st.insert(s[j]);
        //             cnt++;
        //             MaxLen = max(MaxLen,cnt);

        //     }
        // }
        //       return MaxLen;

        //     unordered_set<char>st;
        //    int n = s.size();
        //    int MaxLen = 0;
        //    int l = 0, r = 0;
        //    while(r < n)
        //    {
        //       if(st.count(s[r]))
        //       {
        //          st.erase(s[l]);
        //           l++;

        //       }
        //       else
        //       {
        //          st.insert(s[r]);
        //          MaxLen = max(MaxLen,r - l + 1);
        //          r++;
        //       }

        //    }
        //     return MaxLen;
        // }

        // Optimal TC-O(N) sc-o(1)
        vector<int> hash(256, -1);
        int MaxLen = 0;
        int l = 0, r = 0;
        int n = s.size();
        while (r < n)
        {
            if (hash[s[r]] != -1)
            {
                if (hash[s[r]] >= l)
                    l = hash[s[r]] + 1;
            }
            hash[s[r]] = r;
            MaxLen = max(MaxLen, r - l + 1);
            r++;
        }
        return MaxLen;
    }
};
