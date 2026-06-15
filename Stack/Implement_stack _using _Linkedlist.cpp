#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
   int data;
   Node *next = nullptr;
   Node(int data)
   {
      this->data = data;
   }
};
class Stack
{
private:
   Node *top = nullptr;
   int size = 0;

public:
   void push(int x)
   {
      Node *temp = new Node(x);
      temp->next = top;
      top = temp;
      size++;
   }
   void pop()
   {
      if (top == nullptr)
      {
         cout << "Stack underflow" << endl;
         return;
      }
      Node *temp = top;
      top = top->next;
      delete temp;
      size--;
   }
   int peek()
   {
      if (top == NULL)
      {
         cout << "stack is empty" << endl;
         return -1;
      }
      return top->data;
   }
   int Size()
   {
      return size;
   }
};
int main()
{
   Stack s;
   int n;
   cout << "Enter the stack size:";
   cin >> n;
   cout << "Enter stack elements";
   for (int i = 1; i <= n; i++)
   {
      int x;
      cin >> x;
      s.push(x);
   }
   cout << "stack size:" << s.Size() << endl;
   cout << "stack top element is:" << s.peek() << endl;
   s.pop();
   cout << "after poping stack size:" << s.Size() << endl;
   cout << "after poping stack top element is:" << s.peek() << endl;
   return 0;
}