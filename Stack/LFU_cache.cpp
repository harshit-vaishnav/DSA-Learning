#include <bits/stdc++.h>
using namespace std;
class LFUCache
{
public:
    int cap;
    int size;
    unordered_map<int, list<vector<int>>::iterator> mpp;
    map<int, list<vector<int>>> freq;
    void MakeMostFreqUsed(int key)
    {
        auto vec = *(mpp[key]);
        int f = vec[2];
        int val = vec[1];

        freq[f].erase(mpp[key]);
        if (freq[f].empty())
        {
            freq.erase(f);
        }
        f++;
        freq[f].push_front({key, val, f});
        mpp[key] = freq[f].begin();
    }

    LFUCache(int capacity)
    {
        cap = capacity;
        size = 0;
    }

    int get(int key)
    {
        if (mpp.find(key) == mpp.end())
            return -1;
        auto vec = *(mpp[key]);
        int val = vec[1];
        MakeMostFreqUsed(key);
        return val;
    }

    void put(int key, int value)
    {
        if (cap == 0)
            return;
        if (mpp.find(key) != mpp.end())
        {
            auto &vec = *(mpp[key]);
            vec[1] = value;
            MakeMostFreqUsed(key);
        }
        else if (size < cap)
        {
            size++;
            freq[1].push_front({key, value, 1});
            mpp[key] = freq[1].begin();
        }
        else
        {
            auto &konsi_list = freq.begin()->second;
            int key_to_be_deleted = (konsi_list.back())[0];
            konsi_list.pop_back();
            if (konsi_list.empty())
            {
                freq.erase(freq.begin()->first);
            }
            freq[1].push_front({key, value, 1});
            mpp.erase(key_to_be_deleted);
            mpp[key] = freq[1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */