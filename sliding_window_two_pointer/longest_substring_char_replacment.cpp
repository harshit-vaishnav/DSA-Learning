#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        // Question  Longest substing with at most  k replacment to make a substring same

        // Brute Force TC-O(N ^ 2) SC - O(1)
        // approach sare substring genrate kar but but twist h isme muje k elements ko chnage karna h but konse k? to uske liye me freq count kar luga har element ki jiski
        // freq jayda hoga yani uske croospoding muje chnages karne h to uski freq
        // 3 4 jitni bhi ayegii agar usko me length me se gata du to bache hue char aajyege
        // ab me ya to k ke barabar ya k se kam changes kar skta hu bs yahi h code
        // int MaxLen = 0;
        // for(int i = 0; i < n; i++)
        // {
        //        vector<int>hash(26,0);
        //        int MxFreq = 0;
        //      for(int j = i; j < n; j++)
        //      {
        //          hash[s[j] - 'A']++;
        //          MxFreq = max(MxFreq,hash[s[j] - 'A']);

        //            int Len = j - i + 1;
        //            if(Len - MxFreq <= k)
        //            {
        //              MaxLen = max(MaxLen,j - i + 1);
        //            }
        //            else break;
        //      }
        // }
        //  return MaxLen;

        //    Optimal solution TC-O(N) SC-O(1)
        int MaxLen = 0;
        int l = 0, r = 0;
        vector<int> hash(26, 0);
        int MaxFreq = 0;

        while (r < n)
        {
            hash[s[r] - 'A']++;
            MaxFreq = max(MaxFreq, hash[s[r] - 'A']);
            if ((r - l + 1 - MaxFreq) > k)
            {
                hash[s[l] - 'A']--;
                l++;
            }
            MaxLen = max(MaxLen, r - l + 1);
            r++;
        }
        return MaxLen;
    }
};