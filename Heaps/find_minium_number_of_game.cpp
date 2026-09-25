class Solution
{
public:
    vector<int> numberGame(vector<int> &nums)
    {

        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());

        vector<int> ans;

        while (!pq.empty())
        {
            int first = pq.top();
            pq.pop();

            int second = pq.top();
            pq.pop();

            ans.push_back(second);
            ans.push_back(first);
        }
        return ans;
    }
};