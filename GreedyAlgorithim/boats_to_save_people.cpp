class Solution
{
public:
    int numRescueBoats(vector<int> &nums, int limit)
    {

        int n = nums.size();

        int cnt = 0;

        sort(nums.begin(), nums.end());
        int i = 0, j = n - 1;

        while (i <= j)
        {
            if (nums[i] + nums[j] <= limit)
            {
                i++;
            }

            j--;
            cnt++;
        }

        return cnt;
    }
};