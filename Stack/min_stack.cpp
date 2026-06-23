#include <bits/stdc++.h>
using namespace std;
// apprroach 1 TC-O(1) SC - O(2*N)
// class MinStack {
// public:
// int min_value = INT_MAX;
//    stack<pair<int,int>>st;
//     MinStack() {

//     }

//     void push(int value) {
//         if(st.empty())
//         {
//          st.push({value,value});
//          }
//         else{
//            int mini = min(value,st.top().second);
//             st.push({value,mini});
//         }
//     }
//     void pop() {
//            st.pop();

//     }

//     int top() {
//        return st.top().first;
//     }

//     int getMin() {
//           return st.top().second;
//     }

// };
// optimal approach  TC-O(1) SC - O(N)
// approach hamne ek minvalue var banaya  jo minvalue ko track karta h
// but agar stack se minium value chali gyi to hame prevminvalue lani hogi
// uske liye ham mathmaticall forumla use karte h

class MinStack
{
public:
    long long min_value = INT_MAX; // take A min_value
    stack<long long> st;           // take a stack
    MinStack()
    {
    }

    void push(int value)
    {
        if (st.empty()) // if stack is empty push the value and set minvalue to the curr value
        {
            st.push(value);
            min_value = value; // set min_value to the current value
        }
        else
        {
            if (value < min_value) // check if a stack value is less then min value
            // if its then use maths formula to prserve and update the min_value to value
            {
                st.push((long long)2 * value - min_value); // use formula to store //new value into the stack
                min_value = value;                         // update min_value to the curr min value
            }
            else
            {
                st.push(value);
            }
        }
    }
    void pop()
    {
        // means agar jo element pop hone vala h  vo minum se chota h to min ko piche lejao
        // yani pahle vali min value set karo uske liye use formula
        if (st.top() < min_value)
        {
            min_value = 2 * min_value - st.top();
        }
        st.pop();
    }

    int top()
    {
        if (st.top() < min_value)
        {
            return min_value;
        }
        return st.top();
    }

    int getMin()
    {
        return min_value;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */