#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxScore(vector<int> &nums, int k)
    {

        // Better aap ko jese 7 size ka array h
        // aapko k = 4 diya h yani 4 elements ko pick karke maxisum sum nikalna h to baki 3 elemets ko hata do na
        // bas vahi kiya pahle totalsum nikal liya fir har n -k window size ka sum nikala or use total sum - windowsum kar diya jise k elements ka sum aagya
        //  n = 7
        // k = 4
        // n - k = 3 yani 3 elemnts ka sum hata do totalsum me se to 4 elemnts ka sum aajyega bas fir ese maxium sum nikal lo

        //  TC-O(N)+O(N-K) SC-O(1)
        // int n = nums.size();
        // int TotalSum = 0;
        // int ans = 0;
        // int Wsize = n - k;
        // int l = 0, r = Wsize - 1;
        //  int sum = 0;

        //   step-1 Calculate totalsum
        // for(int i = 0; i < n; i++)
        // {
        //      TotalSum += nums[i];
        // }

        //   striver pattern 1 for exact k size window sum
        // for(int i = 0; i <= r; i++)
        // {
        //    sum += nums[i];
        // }
        // ans = max(ans,(TotalSum - sum));
        // while(r < n - 1)
        // {
        //     sum -= nums[l];
        //     l++;
        //     r++;
        //     sum += nums[r];
        //    ans = max(ans,(TotalSum - sum)); // comapre
        // }
        //  return ans;

        //  Most Optimal  // TC-O(2k) SC -O(1)
        // approach- mere pass 2 choice h ya to left se lo ya right se lo
        // jese sare left se liya sare right se liya aadhe left aadhe right ese
        // to kyu na me sare left ka pahle sum nikal lu fir har bar ek digit ko left se kam karu or right se badhau
        // jese allleftsum then -onedigitleft and and right bas yahi kiya h
        int n = nums.size();
        int l = k - 1, r = n - 1;
        int sum = 0, MaxSum = 0;

        // step-1 sare left sum nikal liya kaha tak k size  tak
        for (int i = 0; i <= l; i++)
        {
            sum += nums[i];
        }
        // usko maxsum me dal diya
        MaxSum = max(MaxSum, sum);
        // step-2 ab left me se 1 minus karo or right vala jodo
        for (int i = l; i >= 0; i--)
        {
            sum -= nums[i];            /// minus karo
            sum += nums[r];            // jodo
            MaxSum = max(MaxSum, sum); // maxsum compare karte raho
            r--;
        }
        return MaxSum;
    }
};