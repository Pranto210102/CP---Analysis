#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
using state = pair<int,int>;
vector<vector<state>>g;
const int mx=2e5+1;
int dis[mx];

void dijkara(int sc){
    for(int i=1;i<=n;i++){
        dis[i]=1e18+1;
    }

    priority_queue<state, vector<state>, greater<state>> pq;
    vector<int>vis(n+1, 0);

     pq.push({0, sc}); // {cost, node}
     dis[sc] = 0;

     while(!pq.empty()){
          int cur_node = pq.top().second;
          int cur_cost = pq.top().first;
          pq.pop();

          if(vis[cur_node])continue;
          vis[cur_node] = 1;

          for(auto v : g[cur_node]){
              int next_node = v.first;
              int wt = v.second;

              if(dis[next_node]> dis[cur_node] + wt){
                 dis[next_node] = dis[cur_node] + wt;

                 pq.push({dis[next_node], next_node});
              }
          }
     }
}

signed main(){
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b, c});
    }

    dijkara({1});

    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
}
