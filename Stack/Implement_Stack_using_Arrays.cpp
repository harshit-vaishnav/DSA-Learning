#include <bits/stdc++.h>
using namespace std;
class Stack
{
private:
  int top = -1;
  int st[10];

public:
  void push(int x)
  {
    if (top >= 9)
    {
      cout << "stack overflow" << endl;
      return;
    }
    top++;
    st[top] = x;
  }
  void pop()
  {
    if (top == -1)
    {
      cout << "stack underflow" << endl;
      return;
    }
    top--;
  }
  int peek()
  {
    if (top == -1)
    {
      cout << "stack is empty" << endl;
      return -1;
    }
    return st[top];
  }
  int size()
  {
    return top + 1;
  }
  bool isEmpty()
  {
    if (top == -1)
      return 1;
    else
      return 0;
  }
};
int main()
{
  Stack s;
  for (int i = 1; i <= 10; i++)
  {
    int x;
    cin >> x;
    s.push(x);
  }
  cout << "stack size is:" << s.size() << endl;
  cout << "top element is:" << s.peek() << endl;
  s.pop();
  cout << "after poping stack size is:" << s.size() << endl;
  cout << "after poping stack top element is:" << s.peek() << endl;
  for (int i = 1; i <= 9; i++)
  {
    s.pop();
  }
  cout << "is stack empty:" << s.isEmpty() << endl;
}