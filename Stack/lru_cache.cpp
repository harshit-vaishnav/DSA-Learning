#include <bits/stdc++.h>
using namespace std;
// class LRUCache {
// public:
// // Brute force TC-O(N^2)
// // dek ek vector le jiski size kitni hogi capapcity ke equal agar
// // ab jab tak capcapity se kam h size tab tak value push karo
// // but size se jayda aajye tab value delete karo konsi value delete karo jo sabse pahle use hui ho ab sabse pahle agar update bhi kiya value ko to vo new ho jayegi to uske liye jab bhhi key mile to usko erase karo start se value save karo fir bad me add kar do
// // egge case agar key same h to new key value dalu to pahel vali ko delte karo

//   vector<pair<int,int>>ans;
//     int n; // size n of ans
//     LRUCache(int capacity) {
//         n = capacity; // initilize size
//     }

//     int get(int key) {
//         for(int i = 0; i < ans.size(); i++)
//         {
//              if(ans[i].first == key) // agar key mili to usko ab update kar do
//               // sabse last me kyunki ham erase front se kr rahe h
//              {
//                 int val = ans[i].second; // save tehe value to return
//                 pair<int,int>temp = ans[i]; // save key value to store in last
//                 ans.erase(ans.begin() + i); // pop the value
//                 ans.push_back(temp); // push to the last
//                  return val; // return val
//              }
//         }
//          return -1;

//     }

//     void put(int key, int value) {
//          // check if their is alredy key is exist
//      for(int i = 0; i < ans.size(); i++)
//      {
//          if(ans[i].first == key)
//          { // if yes then update new key value but before that delete curr key value
//              ans.erase(ans.begin() + i);
//              ans.push_back({key,value});
//              return;
//          }
//      }
// // if size is not grater push into last
//      if(ans.size() < n)
//      {
//          ans.push_back({key,value});
//      }
//      // if gretaer then then erase front
//     //  and then push
//      else{
//          ans.erase(ans.begin());
//          ans.push_back({key,value});
//      }
//     }
// };

//  Optimal Solution TC-O(1)
class LRUCache
{
public:
    list<int> dll;

    unordered_map<int, pair<list<int>::iterator, int>> mpp;

    int n;
    void MostRecentlyused(int key)
    {
        dll.erase(mpp[key].first);
        dll.push_front(key);
        mpp[key].first = dll.begin();
    }

    LRUCache(int capacity)
    {

        n = capacity; // initilize size
    }

    int get(int key)
    {

        if (mpp.find(key) == mpp.end())
            return -1;

        MostRecentlyused(key);

        return mpp[key].second;
    }
    void put(int key, int value)
    {
        if (mpp.find(key) != mpp.end())
        {
            mpp[key].second = value;
            MostRecentlyused(key);
        }
        else
        {
            dll.push_front(key);
            mpp[key] = {dll.begin(), value};
            n--;
        }
        if (n < 0)
        {
            int lastKey = dll.back();
            dll.pop_back();
            mpp.erase(lastKey);
            n++;
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */