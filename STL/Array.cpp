#include<bits/stdc++.h>
using namespace std;
int main()
{ 

array<int,4> a={1,2,3,6};
int size=a.size();
for(int i=0;i<a.size();i++)
cout<<a[i]<<endl;



cout<<a.at(2)<<endl;

cout<<"empty or not=>:"<<a.empty()<<endl;
cout<<"first=>: "<<a.front()<<endl;
cout<<"last=>:"<<a.back()<<endl;
}