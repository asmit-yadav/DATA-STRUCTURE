#include<bits/stdc++.h>
using namespace std;
int main()
{
    int v,e;
    cout<<"how many vertices are there in  the graph"<<endl;
    cin>>v;
     cout<<"how many edge are there in  the graph"<<endl;
    cin>>e;
    vector<int> adjlist[v];
    int a,b;
    for(int i=1;i<=e;i++)
    {
        cout<<"enter the point of the edge"<<endl;
        cin>>a>>b;
        adjlist[a].push_back(b);
        // adjlist[b].push_back(a);

    }
     for(int i=0;i<v;i++)
    {
        cout<<i;
        for(int j=0;j<adjlist[i].size();j++)
        {
            cout<<"->"<<adjlist[i][j];
        }
        cout<<endl;
    }
    vector<int> out(v);
    for(int i=0;i<v;i++)
    {
        out[i]=adjlist[i].size();
    }
    cout<<"outdegree is "<<endl;
    for(int i=0;i<v;i++)
    cout<<out[i]<<" ";


    vector<int> dat(v,0);
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<adjlist[i].size();j++)
        {
            dat[adjlist[i][j]]++;
        }
    }

cout<<"indegree are=>:"<<endl;
    for(int i=0;i<v;i++)
    cout<<dat[i]<<" ";

   queue<int> q;
   for(int i=0;i<v;i++)
   {
    if(dat[i]==0);
    q.push(i);
   }
 cout<<endl;
 while(!q.empty())
 {
    int x=q.front();
    q.pop();
    for(auto y :adjlist[x])
    {
        dat[y]=dat[y]-1;
        if(dat[y]==0)
        {
            q.push(y);
        }
    }
 }
 vector<int>ans;
 for(auto i:ans)
 {
      cout<<i<<" ";
 }

}