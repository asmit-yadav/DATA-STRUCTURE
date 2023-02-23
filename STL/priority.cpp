#include <iostream>
#include <queue>
using namespace std;
int main()
{
    //max heap
    priority_queue<int> maxi;
//min heap;
priority_queue<int ,vector<int>,greater<int>> mini;
maxi.push(1);
maxi.push(4);
maxi.push(2);
maxi.push(8);
maxi.push(10);
int n=maxi.size();
for(int i=0;i<n;i++)
{
    cout<<maxi.top()<<" ";
    maxi.pop();
}
cout<<endl;
mini.push(1);
mini.push(4);
mini.push(2);
mini.push(8);
mini.push(10);
for(int i=0;i<n;i++)
{
    cout<<mini.top()<<" ";
    mini.pop();
}
}