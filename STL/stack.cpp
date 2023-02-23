#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<string> s;
    s.push("asmit");
    s.push("nitesh");
    s.push("yadav");
    cout << "top element=>: " << s.top() << endl;
    s.pop();
    cout << "top element=>: " << s.top() << endl;
    cout << "empty=>: " << s.empty() << endl;
    cout << "size=>: " << s.size() << endl;
}