#include<bits/stdc++.h>
using namespace std;
class Queue
{
    private:
    int currsize = 0,start = -1,end = -1;
    int size = 10;
    int q[10];
    public:
    void push(int x)
    {
     if(currsize >= size)
     {
         cout<<"queue overflow"<<endl;
         return;
     }
      if(currsize == 0)
      {
        start ++;
        end++;
      }
      else{
          end = (end + 1) % size; 
      }
       q[end] = x;
       currsize++;
    }
     int pop()
     {
         if(currsize == 0)
         {
             cout<<"queue is underflow"<<endl;
             return -1;
         }
         int element = q[start];
         if(currsize == 1)
         {
             start = -1;
             end = -1;
         }
         else
         {
            start = (start +1) % size;
         }
         currsize--;
         return element;
     }
      int peek()
      {
        if(currsize == 0) 
        {
             cout<<"queue is empty"<<endl;
             return -1;
        }
        return q[start];
      }
      int size()
      {
        return currsize;
      }

};
int main()
{
Queue q;
for(int i = 1; i <= 10; i++)
  {
     int x;
     cin>>x;
     q.push(x);
  }
   cout<<"queue size is:"<<q.size()<<endl;
   cout<<"top element is:"<<q.peek()<<endl;
   int ele = q.pop();
    cout<<"the pop element is:"<<ele<<endl;
   cout<<"after poping queue size is:"<<q.size()<<endl;
   cout<<"after poping quque top element is:"<<q.peek()<<endl;
}