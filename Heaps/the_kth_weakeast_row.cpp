class Solution
{
public:
    int GiveCnt(vector<int> &row)
    {

        int low = 0, high = row.size();

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (row[mid] == 1)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {

        int n = mat.size();
        int m = mat[0].size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < n; i++)
        {
            int cnt = GiveCnt(mat[i]);
            pq.push({cnt, i});
        }

        vector<int> ans;

        while (k != 0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};