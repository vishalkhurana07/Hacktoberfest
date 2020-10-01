#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<int>&color,int c,int v,vector<vector<int>>&graph) {
  
  for(int i=0;i<v;i++)
  {
      if(graph[v][i]==1 && color[i] == c)
      {
          return false;
      }
  }
  return true;

}

bool isBipartite(int v,vector<vector<int>>&graph,int count,vector<int>&color,int m)
{
    if(count==v)
    {
        return true;
    }

   bool res = false;
    for(int c=1;c<=m;c++)
    {
        if(isSafe(color,c,count,graph))
        {
            color[count] = c;

            res = isBipartite(v,graph,count+1,color,m);
           
            color[count] = 0;
        }

    }

    return res;


}
int main()
{
    int v;
    cin>>v;
    int m;
    cin>>m;
    vector<vector<int>> graph(v,vector<int>(v,0));

    for(int i=0;i<v;i++) {
        for(int j=0;j<v;j++) {
            cin>>graph[i][j];
        }
    }
    vector<int>color(v,0);
    bool ans = isBipartite(v,graph,0,color,m);
    cout<<ans<<endl;

}
