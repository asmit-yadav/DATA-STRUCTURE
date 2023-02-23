#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // vector<int> v(10);
    // cout << "capacity=>: " << v.capacity() << endl;
    // v.push_back(10);
    // cout << "capacity=>: " << v.capacity() << endl;
    // v.push_back(11);
    // cout << "capacity=>: " << v.capacity() << endl;
    // v.push_back(12);
    // cout << "capacity=>: " << v.capacity() << endl;
    // v.push_back(13);
    // cout << "capacity=>: " << v.capacity() << endl;
    // v.push_back(13);
    // cout << "capacity=>: " << v.capacity() << endl;
    // cout<<"size=>:"<<v.size()<<endl;
    // for(auto i:v)
    // cout<<i<<" ";
    // for (auto i : v)
    //     cout << i << " ";
    // cout << endl;
    // cout << v.capacity() << endl;
    // v.push_back(11);
    // cout << v.capacity() << endl;
    // cout << v.size()<<endl;

    vector<int> v[5];
    // for (int i = 0; i < 5; i++)
    //     cout << v[i].size() << " ";

    v[0].push_back(1);
    v[0].push_back(2);
    v[0].push_back(3);
      v[0].push_back(3);
    v[1].push_back(4);
    v[1].push_back(5);
     v[1].push_back(4);
    v[1].push_back(5);
    v[2].push_back(4);
    v[2].push_back(4);
    v[2].push_back(4);
    v[2].push_back(4);
    v[3].push_back(4);
    v[3].push_back(4);
    v[3].push_back(4);
    v[3].push_back(4);
    v[4].push_back(4);
    v[4].push_back(4);
    v[4].push_back(4);
    v[4].push_back(4);
    for(int i=0;i<5;i++)
    {
        cout<<i<<":";
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}