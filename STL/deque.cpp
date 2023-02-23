#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int main()
{
    deque<int> d;
    d.push_back(1);
    d.push_front(2);
    for (int i : d)
        cout << i << " ";

    d.pop_back();
    cout << endl;

    for (int i : d)
        cout << i << " ";

    cout << endl;
    cout << "size =>:" << d.size() << endl;
    d.erase(d.begin() + 1);
    cout << "size =>:" << d.size() << endl;
}