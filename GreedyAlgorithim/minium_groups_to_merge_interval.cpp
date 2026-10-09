class Solution
{
public:
    int minGroups(vector<vector<int>> &nums)
    {
        int n = nums.size();

        vector<int> b1;
        vector<int> b2;

        for (int i = 0; i < n; i++)
        {
            b1.push_back(nums[i][0]);
            b2.push_back(nums[i][1]);
        }

        sort(b1.begin(), b1.end());
        sort(b2.begin(), b2.end());

        int i = 0, j = 0;

        int cnt = 0, ans = 0;

        while (i < n)
        {
            if (b1[i] <= b2[j])
            {
                cnt++;
                i++;
            }
            else
            {
                cnt--;
                j++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};