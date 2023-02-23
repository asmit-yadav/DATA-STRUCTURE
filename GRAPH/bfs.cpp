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
        adjlist[b].push_back(a);

    }
     for(int i=0;i<v;i++)
    {
        cout<<i<<":";
        for(int j=0;j<adjlist[i].size();j++)
        {
            cout<<adjlist[i][j]<<" ";
        }
        cout<<endl;
    }
    queue<int> q;
    vector<int> status(v);
    q.push(0);
    status[0]=1;
    while(q.empty()!=1)
    {
        int x=q.front();
        q.pop();
        for(int j=0;j<adjlist[x].size();j++)
        {
            if(status[adjlist[x][j]]==0)
            {
                q.push(adjlist[x][j]);
                status[adjlist[x][j]]=1;
            }
        }
        cout<<x<<" ";
    }
}