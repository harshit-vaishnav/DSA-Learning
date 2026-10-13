class Solution
{
public:
    vector<int> maxKDistinct(vector<int> &nums, int k)
    {

        int n = nums.size();

        sort(nums.begin(), nums.end(), greater<int>());

        vector<int> ans;

        ans.push_back(nums[0]);

        int i = 1;

        while (i < n && ans.size() != k)
        {
            if (ans.back() != nums[i])
                ans.push_back(nums[i]);
            i++;
        }

        return ans;
    }
};