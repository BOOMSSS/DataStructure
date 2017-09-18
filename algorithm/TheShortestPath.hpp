#ifndef THE_SHORTEST_PATH_HPP
#define THE_SHORTEST_PATH_HPP
#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include "Node.hpp"

using namespace std;
const int INF = 0x3e3e3e3e;
const int maxn = 100;

class TheShortestPath {
public:
int map[maxn][maxn];
int pre[maxn],dis[maxn];
bool vis[maxn];
int n,m;
vector<node> edges;

TheShortestPath(){
  n = 6;
  for (int i=1; i<=n;i++)
      for (int j=1;j<=n;j++){
          if (i == j) map[i][j] = 0;
          else map[i][j] = map[j][i] = INF;
      }
}

void set_n(int _n){
  n = _n;
  for (int i=1; i<=n;i++)
      for (int j=1;j<=n;j++){
          if (i == j) map[i][j] = 0;
          else map[i][j] = map[j][i] = INF;
      }
}

void reset() {
    n = maxn;
    for (int i=1; i<=n;i++)
        for (int j=1;j<=n;j++){
            if (i == j) map[i][j] = 0;
            else map[i][j] = map[j][i] = INF;
        }
}


void add(int s, int t, int weight) {
  map[s][t] = weight;
  map[t][s] = weight;
  edges.push_back(node(s, t, weight));
}

vector<node> get_all_edges() {
  return edges;
}

vector<int> Dijkstra(int s)
{
    memset(dis,0x3f,sizeof(dis));
    memset(pre,-1,sizeof(pre));
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;++i)
    {
        dis[i]=map[s][i];
        pre[i]=s;
    }
    dis[s]=0;
    vis[s]=true;
    for(int i=2;i<=n;++i)
    {
        int mindist=INF;
        int u=s;
        for(int j=1;j<=n;++j)
            if((!vis[j])&&dis[j]<mindist)
            {
                u=j;
                mindist=dis[j];
            }
        vis[u]=true;
        for(int j=1;j<=n;++j)
            if((!vis[j])&&map[u][j]<INF)
            {
                if(map[u][j]+dis[u]<dis[j])
                {
                    dis[j]=map[u][j]+dis[u];
                    pre[j]=u;
                }
            }
    }
    vector<int> ans(dis, dis + n);
    return ans;
}

vector<vector<int> > GetAns() {
    vector<vector<int> > ret(n + 1, vector<int>(n + 1, 0x3e3e3e3e));
    for (int i = 1; i <= n; i++) {
        ret[i][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ret[i][j] = map[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (ret[i][j] > ret[i][k] + ret[k][j])
                    ret[i][j] = ret[i][k] + ret[k][j];
            }
        }
    }
    return ret;
}

};
#endif
