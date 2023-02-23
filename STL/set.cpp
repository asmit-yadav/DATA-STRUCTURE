#include <iostream>
#include <set>
using namespace std;
int main()
{
    set<int>s;
    s.insert(5);
    s.insert(5);
    s.insert(4);
    s.insert(0);
    for(auto i:s)
    cout<<i<<endl;

   cout<<"count"<<s.count(5)<<endl;
}