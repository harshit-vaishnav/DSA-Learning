#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int celebrity(vector<vector<int>> &M)
    {

        // Brute Force TC-O(N^2) SC-O(1)
        // int m = M[0].size();
        // for(int i = 0; i < n; i++)
        // {
        //      bool rowzero = true;
        //     for(int j = 0; j < m; j++)
        //    {
        //         if(M[i][j] == 1)
        //         {
        //              rowzero = false;
        //              break;
        //         }
        //     }
        //     if(rowzero)
        //     {
        //          bool colone = true;
        //       for(int k = 0; k < n; k++)
        //       {
        //          if(M[k][i] == 0 && k != i)
        //          {
        //             colone = false;
        //             break;
        //          }
        //       }
        //       if(colone) return i;
        //     }

        // }
        //  return -1;

        //  Optimal Solution
        int n = M.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            st.push(i);
        }
        while (st.size() > 1)
        {
            int i = st.top();
            st.pop();
            int j = st.top();
            st.pop();
            if (M[i][j] == 0)
            {
                st.push(i);
            }
            else
            {
                st.push(j);
            }
        }
        int celb = st.top();
        for (int i = 0; i < n; i++)
        {
            if (i != celb && (M[celb][i] == 1 || M[i][celb] == 0))
            {
                return -1;
            }
        }
        return celb;
    }
};
