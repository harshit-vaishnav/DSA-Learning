class Solution
{
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[1] < b[1];
    }
    int maxMeetings(vector<int> &start, vector<int> &end)
    {

        vector<vector<int>> v;
        int n = start.size();

        for (int i = 0; i < n; i++)
        {
            v.push_back({start[i], end[i]});
        }

        sort(v.begin(), v.end(), comp);

        int maxrange = v[0][1];

        int ans = 1;

        for (int i = 1; i < v.size(); i++)
        {
            if (v[i][0] > maxrange)
            {
                ans++;
                maxrange = v[i][1];
            }
        }

        return ans;
    }
};