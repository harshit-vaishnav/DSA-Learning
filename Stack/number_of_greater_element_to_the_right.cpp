#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices)
    {
        // TC-O(N^2) SC - O(N)
        int idx = indices.size();
        int n = arr.size();
        vector<int> ans;
        for (int i = 0; i < idx; i++)
        {
            int cnt = 0;
            int target = arr[indices[i]];
            for (int j = indices[i] + 1; j < n; j++)
            {
                if (arr[j] > target)
                    cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};