class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &nums)
    {

        int n = nums.size();

        long long waitingTime = 0;
        long long foodTime = 0;

        for (int i = 0; i < n; i++)
        {
            foodTime = max((long long)nums[i][0], foodTime);

            foodTime += nums[i][1];

            waitingTime += foodTime - nums[i][0];
        }

        return (double)waitingTime * 1.0 / n;
    }
};