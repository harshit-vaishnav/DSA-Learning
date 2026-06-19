#include <bits/stdc++.h>
using namespace std;
/* question bolta h tume ek string di gyi hogi jo ki vaild parenthess ki hogi
tume batna h ki usme koi duplicate parenthess h ya nahi agar h to return true else return false
Eg - "((x + y))" output true
explanation dek ek expression ke liye sirf ek pair of  parenthess chaiye yaha 2 h isliye true
Eg- "(X+Y)" output false yaha ek expression ke liye ek pair h
eg-((x+y) + ((z)) output true: yaha z ke liye 2 pair of expression h


//approach TC-O(N) SC-O(N)
kyu na me har ek expression ko ek pair se cancel kar du yani jab bracket open hua to
usko stack me push karo fir bracket me jab close bracket aya to check kar lo
stack ke top  me kya opening bracket tha kya agar tha to vahi return  true
eg () ye true dega kyunki 0 expression 1 pair stack ke top me ( fir jab close aya to true dega
agar  closing bracket ke time stack me expressin tha to usko remove kar do jab tak open nahi aye
fir open ko bhi remove kar do
eg (x+y) stack me ( x + y jab loop ) read karega to dekega top of the stack kya h
yaha expression h to pop karo untill and unless pura expression cancel na ho jaye
*/

bool isDuplicate(string &s)
{
    stack<char> st;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] != ')') // push untill a expression is end
        {
            st.push(s[i]);
        }
        else
        {
            if (st.top() == '(') // dupliacte ()
                return true;
            else
            {
                while (st.top() != '(') // expression remove
                {
                    st.pop();
                }
                st.pop();
            }
        }
    }
    return false;
}