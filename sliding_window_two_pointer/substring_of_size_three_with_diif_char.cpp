#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countGoodSubstrings(string s)
    {
        int n = s.size();
        if (n < 3)
            return 0;

        int cnt = 0;

        // precomputation
        if ((s[0] != s[1]) && (s[0] != s[2]) && (s[1] != s[2]))
            cnt++;

        // pointer set or creating fix window
        int l = 0, r = 2;
        while (r < n - 1)
        {
            l++;
            r++;
            if ((s[l] != s[l + 1]) && (s[l] != s[r]) && (s[l + 1] != s[r]))
            {
                cnt++;
            }
        }
        return cnt;
    }
};