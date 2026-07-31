#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        int n = code.size();
        if (k == 0)
            return vector<int>(n, 0);
        else if (k > 0)
        {
            int sum = 0;
            int l = 1, r = k;
            vector<int> ans;
            for (int i = l; i <= r; i++)
            {
                sum += code[i % n];
            }

            ans.push_back(sum);

            while (ans.size() < n)
            {
                sum = sum - code[l % n];
                l++;
                r++;
                sum = sum + code[r % n];
                ans.push_back(sum);
            }

            return ans;
        }
        else
        {
            k = -k;
            int sum = 0;
            int l = n - k;
            int r = n - 1;

            vector<int> ans;

            for (int i = l; i <= r; i++)
                sum += code[i];

            ans.push_back(sum);

            while (ans.size() < n)
            {
                sum -= code[l % n];
                l++;

                r++;
                sum += code[r % n];

                ans.push_back(sum);
            }

            return ans;
        }
        return {};
    }
};