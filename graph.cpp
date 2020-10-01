#include<bits/stdc++.h>
using namespace std;
class Edge
{
public:
int u;
Edge(int u)
{
    this->u=u;

}

};
class node
{
public:
int i;
int j;
int val;
node(int i,int j,int val)
{
    this->i=i;
    this->j=j;
    this->val=val;
}
};
vector<vector<Edge*>>graph;
void addEdge(int u,int v)
{
    graph[u].push_back(new Edge(v));
    graph[v].push_back(new Edge(u));
}

void initialise(int n)
{
    for(int i=0;i<n;i++)
    {
        vector<Edge*>arr;
        graph.push_back(arr);
    }
}
bool isSafe(int i,int j,vector<vector<int>>&mat,vector<vector<bool>>&vis)
{
    if(i>=0&&i<mat.size()&&j>=0&&j<mat[0].size()&&mat[i][j]!=0&&!vis[i][j])
    {
        return true;
    }
    return false;
}
int bfs(int src_i,int src_j,vector<vector<int>>&mat)
{
    int n=mat.size();
    queue<node>q;
    vector<vector<bool>>visited(n,vector<bool>(mat[0].size()));
    node k(src_i,src_j,mat[src_i][src_j]);
        q.push(k);
        visited[src_i][src_j]=true;
        int level=0;
    while(!q.empty())
    {
        int size=q.size();
        while(size>0)
        {
            node front=q.front();
            q.pop();
            int curr_i=front.i;
            int curr_j=front.j;
            int val=front.val;
            if(val==2)
            {
                return level;
            }
            int row[]={-1,0,1,0};
            int col[]={0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                if(isSafe(curr_i+row[i],curr_j+col[i],mat,visited))
                {
                    visited[curr_i+row[i]][curr_j+col[i]]=true;
                    node ne(curr_i+row[i],curr_j+col[i],mat[curr_i+row[i]][curr_j+col[i]]);
                    q.push(ne);
                }

            }
            size--;




        }
        level++;
    }
    return -1;
}
void dijkstra(int src)
{
    
}


int main()
{
    int n;
    int m;
    int src_i,src_j,des_i,des_j;
    cin>>n>>m;
     vector<vector<int>>matrix(n,vector<int>(m));
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<m;j++)
         {
             int val;
             cin>>val;
             matrix[i][j]=val;
             if(val==1)
             {
                 src_i=i;
                 src_j=j;
             }
         
         }
     }
     
     
     int ans=bfs(src_i,src_j,matrix);
     cout<<ans<<endl;
    return 0;
}
