#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<string> q;
    q.push("asmit");
    q.push("nitesh");
    q.push("yadav");

    cout<<"top=>:"<<q.front()<<endl;
    q.pop();
     cout<<"top=>:"<<q.front()<<endl;
      cout<<"size=>:"<<q.size()<<endl;
}