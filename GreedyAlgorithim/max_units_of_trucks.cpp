class Solution
{
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>> &nums, int cap)
    {

        int n = nums.size();

        sort(nums.begin(), nums.end(), comp);

        int i = 0, ans = 0;

        while (i < n && cap > 0)
        {
            if (nums[i][0] <= cap)
            {
                ans += nums[i][0] * nums[i][1];
                cap -= nums[i][0];
            }
            else
            {
                ans += cap * nums[i][1];
                cap = 0;
            }
            i++;
        }

        return ans;
    }
};