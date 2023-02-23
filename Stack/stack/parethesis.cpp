#include <iostream>
#include <stack>
using namespace std;
// bool isValid(string expression)
// {
//     // Write your code here.
//     stack<char> s;
//     for (int i = 0; i < expression.length(); i++)
//     {
//         char ch = expression[i];
//         if (ch == '[' || ch == '{' || ch == '(')
//         {
//             s.push(ch);
//         }
//         else
//         {
//             if (!s.empty())
//             {
//                 char top = s.top();
//                 if (ch == '}' && top == '{' || ch == ')' && top == '(' || ch == ']' && top == '[')
//                 {
//                     s.pop();
//                 }
//                 else
//                 {
//                     return false;
//                 }
//             }
//             else
//             {
//                 return false;
//             }
//         }
//     }
//     if (s.empty())
//     {
//         return true;
//     }
//     else
//         return false;
// }
bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '[' || ch == '{' || ch == '(')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty())
            {
                char top = st.top();
                if (ch == ']' && top == '[' || ch == '}' && top == '{' || ch == ')' && top == '(')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if (st.empty())
    {
        return true;
    }
    else
        return false;
}
int main()
{
    string s = "{[";
    if (isValid(s))
    {
        cout << "1";
    }
    else
        cout << "0";
}