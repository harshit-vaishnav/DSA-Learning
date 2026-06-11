#include<bits/stdc++.h>
using namespace std;
class Stack
{
     public:
     queue<int>q;
     void push(int x)
     {
         int s = q.size();
         q.push(x);
         for(int i = 1; i <= s-1; i++)
         {
            q.push(q.front()); 
            q.pop();
         }
     }
      void pop()
      {
         if(q.empty()) 
         {
            cout<<"stack underflow"<<endl;
            return;
         }
          q.pop();
      }
      int Size()
      {
        return q.size();
      }
       int peek()
       {
         if(q.empty())
         {
            cout<<"quque is empty"<<endl;
             return -1;
         }
        return q.front();
       }
      
};
int main()
{ 
    Stack s;
    int n;
    cout<<"Enter stack size";
    cin>>n;
    cout<<"Enter quque elemets:";
    for(int i = 1; i <= n; i++)
    {
         int x;
          cin>>x;
          s.push(x);
    }
  
   cout<<"stack top:"<<s.peek()<<endl;
   cout<<"stack size:"<<s.Size()<<endl;
    s.pop();
    cout<<"after poping an element stack  top:"<<s.peek()<<endl;
    cout<<"after poping an element stack size:"<<s.Size()<<endl;
    return 0;

}