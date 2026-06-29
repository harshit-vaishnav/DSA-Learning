#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // int solve(vector<int>& height,int idx)
    // {
    //    int n = height.size();
    //   int LeftM = height[0];
    //   for(int i  = 0; i <= idx; i++)
    //   {
    //       LeftM= max(LeftM,height[i]);
    //   }
    //     return LeftM;
    // }
    // int solve1(vector<int>& height,int idx)
    // {
    //   int n = height.size();
    //   int RightM = height[n - 1];
    //   for(int i  = n - 1; i >= idx; i--)
    //   {
    //       RightM = max(RightM,height[i]);
    //   }
    //     return RightM;
    // }
    int trap(vector<int> &height)
    {

        // Brute force
        int n = height.size();
        int Twater = 0;
        // for(int i = 1; i < n - 1; i++)
        // {
        //      int LeftMax = solve(height,i);
        //      int RightMax = solve1(height,i);
        //      int water = min(LeftMax,RightMax) - height[i];
        //      Twater += water;
        // }
        //  return Twater;

        //    Better approach TC-O(3N) SC - O(2N)
        // vector<int>Leftmax(n);
        // vector<int>Rightmax(n);
        // Leftmax[0] = height[0];

        // for(int i = 1; i < n; i++)
        // {
        //    Leftmax[i] = max(Leftmax[i - 1],height[i]);
        // }
        //   Rightmax[n - 1] = height[n - 1];
        // for(int i = n - 2; i >= 0; i--)
        // {
        //   Rightmax[i] = max(Rightmax[i + 1],height[i]);
        // }
        //  for(int i = 0; i < n; i++)
        // {
        //      int water = min(Leftmax[i],Rightmax[i]) - height[i];
        //      Twater += water;
        // }
        //  return Twater;

        // optimal TC-O(N) SC -O(1)
        int l = 0, r = n - 1;
        int Rmax = 0, Lmax = 0;
        while (l < r)
        {
            Lmax = max(Lmax, height[l]);
            Rmax = max(Rmax, height[r]);

            if (height[l] < height[r])
            {
                Twater += Lmax - height[l];
                l++;
            }
            else
            {
                Twater += Rmax - height[r];
                r--;
            }
        }
        return Twater;
    }
};