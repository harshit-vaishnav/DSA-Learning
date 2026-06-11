#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next = nullptr;
    Node(int data)
    {
      this->data = data;
    }
};
class Queue
{
     private:
     Node* start = nullptr;
     Node* end = nullptr;
     int size = 0;
     public:
     void push(int x)
     {
         Node* temp = new Node(x);
        if(size == 0)
        {
            start = end = temp;
        }
        else{
             end->next = temp;
             end = temp;
        }
         size++;
     }
     void pop()
     {
         if(start == nullptr)
         {
             end = nullptr;
             cout<<"Queue Underflow"<<endl;
             return;
         }
         
           Node* temp = start;
            start = start->next;
            delete temp;
             size--;
             if(start == nullptr) end = nullptr;
     }
     int peek()
     {
         if(start == nullptr)
         {
             cout<<"Queue empty"<<endl;
             return -1;
         }
          return start->data;
     }
     int Size()
     {
         return size;
     }
};
int main()
{
     Queue q;
     int n;
     cout<<"Enter Queue size:";
     cin>>n;
     cout<<"Enter Queue elements:";
     for(int i = 1; i <= n; i++)
     {
          int x;
          cin>>x;
         q.push(x);
     }
     cout<<"Queue size is:"<<q.Size()<<endl;
     cout<<"Queue front element is:"<<q.peek()<<endl;
     q.pop();
     cout<<"Queue size is:"<<q.Size()<<endl;
     cout<<"Queue front is:"<<q.peek()<<endl;
}