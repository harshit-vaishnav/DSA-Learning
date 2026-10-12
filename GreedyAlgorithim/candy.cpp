class Solution
{
public:
    int candy(vector<int> &nums)
    {

        int n = nums.size();

        vector<int> count(n, 1);

        int candies = 0;

        // left to right travsel

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                count[i] = count[i - 1] + 1;
            }
        }

        // right to left travsel with max value

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] > nums[i + 1])
            {
                count[i] = max(count[i], count[i + 1] + 1);
            }
            candies += count[i];
        }
        candies += count[n - 1];
        return candies;
    }
};