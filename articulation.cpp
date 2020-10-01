#include<bits/stdc++.h>
using namespace std;
class Edge
{
 public:
 int v;
 Edge(int v)
 {
     this->v=v;
 }

};
vector<vector<Edge*>>graph;
void initialise(int n)
{
    graph.clear();
    vector<Edge*>arr;
    for(int i=0;i<n;i++)
    {
        graph.push_back(arr);
    }
}
void addEdge(int u,int v)
{
    graph[u].push_back(new Edge(v));
    graph[v].push_back(new Edge(u));

}
int cnt=0;
vector<vector<int>>ans;

void articulationPoint(int u,int p,vector<int>&disc,vector<int>&low,vector<bool>&vis)
{
     disc[u]=low[u]=cnt++;
     vis[u]=true;
     for(int i=0;i<graph[u].size();i++)
     {
         if(graph[u][i]->v==p)
         {
             continue;
         }
         else if(!vis[graph[u][i]->v])
         {
           articulationPoint(graph[u][i]->v,u,disc,low,vis);
           if(disc[u]<low[graph[u][i]->v])
           {
               ans.push_back({u,graph[u][i]->v});
               
           }
           low[u]=min(low[u],low[graph[u][i]->v]);

         }
         else
         {  
             low[u]=min(low[u],disc[graph[u][i]->v]);
         }
         
     }
     


}


int main()
{
    int n;
    cin>>n;
    initialise(n+1);
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        addEdge(u,v);
    }
    int src=graph[0][0]->v;
    vector<int>disc(n+1,0);
vector<int>low(n+1,0);
vector<bool>vis(n+1,0);
    articulationPoint(src,-1,disc,low,vis);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[0].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;
}



// https://www.softwaretestinggenius.com/tutorial-6-dd-path-testing-case-of-a-quadratic-equation/
