#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findnsl(vector<int> nums)
    {
        stack<int> st;
        int n = nums.size();
        vector<int> nsl(n);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] > nums[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                nsl[i] = -1;
            }
            else
            {
                nsl[i] = st.top();
            }
            st.push(i);
        }
        return nsl;
    }
    vector<int> findnsr(vector<int> nums)
    {

        int n = nums.size();
        stack<int> st;
        vector<int> nsr(n);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                nsr[i] = n;
            }
            else
            {
                nsr[i] = st.top();
            }
            st.push(i);
        }
        return nsr;
    }
    int largestRectangleArea(vector<int> &heights)
    {

        // Brute Force TC-O(N^2) SC-O(1)
        //   int n = heights.size();
        // int Maxarea = 0;
        // for(int i = 0; i < n; i++)
        // {
        //      int Minheight = heights[i];
        //     for(int j = i; j < n; j++)
        //     {
        //       Minheight = min(Minheight,heights[j]);
        //       Maxarea = max(Maxarea,(Minheight * (j - i + 1)));
        //     }
        // }
        // return Maxarea;
        //    Optimal TC-O(2*N) SC-O(N)
        // approach yeh problem bhi sum of subaray jesi hi h kuch nhi bs formula chnage h
        // isme ham rightcnt + leftcnt -1
        // baki esi h appraoch ki ham dek lege har ek element kitna contribute kar raha h ans me hamre fir usko multiply karva dege ans se hamre or kya
        int MaxArea = 0;
        vector<int> nsl = findnsl(heights);
        vector<int> nsr = findnsr(heights);
        int n = heights.size();
        for (int i = 0; i < n; i++)
        {
            int leftcnt = i - nsl[i];
            int rightcnt = nsr[i] - i;
            int width = rightcnt + leftcnt - 1;
            int area = heights[i] * width;
            MaxArea = max(MaxArea, area);
        }
        return MaxArea;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int MaxArea = 0;
        vector<vector<int>> Psum(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++)
        {
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += matrix[i][j] - '0';
                if (matrix[i][j] == '0')
                    sum = 0;
                Psum[i][j] = sum;
            }
        }
        for (int i = 0; i < n; i++)
        {
            MaxArea = max(MaxArea, largestRectangleArea(Psum[i]));
        }
        return MaxArea;
    }
};