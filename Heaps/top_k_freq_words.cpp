class Solution
{
public:
    struct cmp
    {
        bool operator()(pair<int, string> &a, pair<int, string> &b)
        {
            if (a.first == b.first)
            {
                return a.second < b.second;
            }

            return a.first > b.first;
        }
    };
    vector<string> topKFrequent(vector<string> &nums, int k)
    {

        int n = nums.size();

        unordered_map<string, int> mpp; // str -> freq;

        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;

        for (auto &it : nums) // o(n)
        {
            mpp[it]++;
        }

        for (auto &it : mpp) // o(n logk)
        {
            string s = it.first;
            int f = it.second;

            pq.push({f, s});
            if (pq.size() > k)
                pq.pop();
        }

        vector<string> ans;

        while (!pq.empty()) // O(klogk)
        {
            int f = pq.top().first;
            string str = pq.top().second;

            ans.push_back(str);
            pq.pop();
        }

        reverse(ans.begin(), ans.end()); // o(k)

        return ans;
    }
};