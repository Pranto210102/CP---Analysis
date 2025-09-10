#include <bits/stdc++.h>
using namespace std;
#define int long long
using state = pair<int,int>;

vector<vector<pair<int,int>>> g;
int n, a, b;
int dis[500100];

void dijkara(int sc){
    for(int i=1;i<= 2*n + 10;i++){
        dis[i]=1e18+1;
    }

    priority_queue<state, vector<state>, greater<state>> pq;
    vector<int>vis(2*n + 10 , 0);

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

signed main() {
    cin >> n >> a >> b;
    int arr[n+1];
    map<int, vector<int>> mp;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        mp[arr[i]].push_back(i);
    }
    g.resize(n + mp.size() + 2);

    for(int i = 1; i < n; i++) {
        g[i].push_back({i+1, b});
        g[i+1].push_back({i, b});
    }

    int Dnode = n+1;
    for(auto &v : mp) {
        for(auto u : v.second) {
            g[Dnode].push_back({u, a});
            g[u].push_back({Dnode, 0});
        }
        Dnode ++;
    }

    int sc;
    cin >> sc;
    dijkara(sc);
    for(int i = 1; i <= n; i++) {
        cout << dis[i] << " ";
    }
    cout << "\n";
}
