#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool lemonadeChange(vector<int> &nums)
    {

        int n = nums.size();
        int five_ka_note = 0;
        int ten_ka_note = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 5)
            {
                five_ka_note++;
            }
            else if (nums[i] == 10)
            {
                if (five_ka_note == 0)
                    return false;
                five_ka_note--;
                ten_ka_note++;
            }
            else
            {
                if (five_ka_note >= 1 && ten_ka_note >= 1)
                {
                    five_ka_note--;
                    ten_ka_note--;
                }
                else if (five_ka_note >= 3)
                {
                    five_ka_note -= 3;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};