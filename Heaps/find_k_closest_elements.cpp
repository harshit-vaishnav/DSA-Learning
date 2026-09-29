class Solution
{
public:
    vector<int> findClosestElements(vector<int> &nums, int k, int x)
    {
        int n = nums.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // distance -> ele

        for (int i = 0; i < n; i++) // o(nlogn)
        {
            int dis = abs(nums[i] - x);
            pq.push({dis, nums[i]});
        }
        vector<int> ans;

        while (k--) // o(klogn)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end()); // o(klogk)

        return ans;
    }
};