#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        //   Optimal Approach using stack
        //     int n = num.size();
        //    stack<int>st;
        //    if(k >= n) return "0";
        //    for(int i = 0; i < n; i++)
        //    {
        //        while(!st.empty() && st.top() > (num[i] - '0')  && k != 0)
        //        {
        //              st.pop();
        //              k--;
        //        }
        //        if(!st.empty() || num[i] != '0')
        //        {
        //               st.push(num[i] -'0');
        //        }
        //    }
        //       while(k > 0 && !st.empty())
        //       {
        //          st.pop();
        //          k--;
        //       }
        //        if(st.empty()) return "0";
        //        string ans = "";
        //        while(!st.empty())
        //        {
        //           char ch = st.top() + '0';
        //         ans.push_back(ch);
        //           st.pop();
        //        }
        //        reverse(ans.begin(),ans.end());
        //      return ans;

        // Optimal TC-O(2*N) SC-O(N)
        //   dek agar muje koi 3-4 digits de or muje bole ki tuje smallest number banana h to
        // to me kese banuaga simple un digit ko left se right me badte order incresing order
        // me rakuga for example jese 4,7,8,1 in digits ka use kar smallest no bana
        //  1478 yahi hoga smallest yani left se right increasing order
        //  same is question me esa hi karna h muje string di h
        //  ab muje inme se har ek digit ko pick karna ans string me dalna or ese dalna ki increasing order hi rahe jo increasing order tode to usko pop karo
        //  to esa hogya na like increasing monotonic stack to bss vahi karna h
        //  ab me stack se bhi bana skta hu ya string ko as a stack bhi bhave karva skta hu

        int n = num.size();
        string ans = ""; // ans string behave as a string
        for (int i = 0; i < n; i++)
        {
            // dek agar ans khali h yani pahala number to rako
            // ab monotonic stack increasing ka yahi codition h st.top > num[i]
            // muje kitni digits remove karnni h only k agar k digits remove ho chuki
            //  ab i dont care ki kese add karna ab chahe increasing me karo chahe decresing not matter
            if (k >= n)
                return "0";
            while (!ans.empty() && ans.back() > num[i] && k != 0)
            {
                ans.pop_back();
                k--;
            }

            // specail bola ki leading zeroes ans string me nhi hoge to thik h ignore it
            if (ans.size() > 0 || num[i] != '0')
            {
                ans.push_back(num[i]);
            }
        }
        // edge case agar man le number pahle se increasing order me tha to k ki value to vahi rahi but me to k digits delete karni thi isliye mene k jab tak 0 nahi hota tab tak ans me se pop karo agar man le k == n ke hota to ans empty ho jayta isliye mene ye loop ese chlaya  or ans empty ho jata to return 0 karvao varna ans
        while (!ans.empty() && k != 0)
        {
            ans.pop_back();
            k--;
        }
        if (ans.empty())
            return "0";
        else
            return ans;
    }
};