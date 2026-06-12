// #include<bits/stdc++.h>
// using namespace std;
// class Queue
// {
//   public:
//     stack<int>s1,s2;
//     void push(int x)
//     {
//         while(!s1.empty())
//         {
//             s2.push(s1.top());
//             s1.pop();
//         }
//           s1.push(x);
//           while(!s2.empty())
//           {
//              s1.push(s2.top());
//               s2.pop();
//           }
//     }
//      void pop()
//      {
//          if(s1.empty()) 
//          {
//             cout<<"queue underflow"<<endl;
//             return;
//          }
//          s1.pop();
//      }
//      int peek()
//      {
//          if(s1.empty()) 
//          {
//             cout<<"queue empty"<<endl;
//             return -1;
//          }
//          return s1.top();
//      }
//       int Size()
//       {
//          return s1.size();
//       }
// };
// int main()
// {
//      Queue q;
//       int n;
//      cout<<"Enter queue size:";
//      cin>>n;
//       cout<<"Enter queue elements:";
//     for(int i = 0; i < n; i++)
//     {
//          int x;
//         cin>>x; 
//          q.push(x);
//     }
//     cout<<"queue size is:"<<q.Size()<<endl;
//     cout<<"queue front element is:"<<q.peek()<<endl;
//     q.pop();
//     cout<<"after poping queue size is:"<<q.Size()<<endl;
//     cout<<"after poping quque front element is:"<<q.peek()<<endl;
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
class Queue
{
  public:
    stack<int>s1,s2;
    void push(int x)
    {
       s1.push(x);
    }
     void pop()
     {
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s2.pop();
        }
        else{
             s2.pop();
        }
     }
     int peek()
     {
         if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
           return s2.top();
        }
        else{
          return  s2.top();
        }
     }
      int Size()
      {
         return s1.size()+s2.size();
      }
};
int main()
{
     Queue q;
      int n;
     cout<<"Enter queue size:";
     cin>>n;
      cout<<"Enter queue elements:";
    for(int i = 0; i < n; i++)
    {
         int x;
        cin>>x; 
         q.push(x);
    }
    cout<<"queue size is:"<<q.Size()<<endl;
    cout<<"queue front element is:"<<q.peek()<<endl;
    q.pop();
    cout<<"after poping queue size is:"<<q.Size()<<endl;
    cout<<"after poping quque front element is:"<<q.peek()<<endl;
    return 0;
}