class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {

        int n = nums1.size();
        int m = nums2.size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        set<pair<int, int>> st;

        int sum = nums1[0] + nums2[0];
        pq.push({sum, {0, 0}});
        st.insert({0, 0});

        vector<vector<int>> ans;
        while (k > 0 && !pq.empty())
        {
            pair<int, int> smallest = pq.top().second;
            int i = smallest.first;
            int j = smallest.second;
            ans.push_back({nums1[i], nums2[j]});
            pq.pop();

            if (i + 1 < n && st.find({i + 1, j}) == st.end())
            {
                int sum = nums1[i + 1] + nums2[j];
                pq.push({sum, {i + 1, j}});
                st.insert({i + 1, j});
            }

            if (j + 1 < m && st.find({i, j + 1}) == st.end())
            {
                int sum = nums1[i] + nums2[j + 1];
                pq.push({sum, {i, j + 1}});
                st.insert({i, j + 1});
            }

            k--;
        }

        return ans;
    }
};