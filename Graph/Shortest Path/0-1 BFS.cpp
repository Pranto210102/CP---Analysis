#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<pair<int,int>>>g;
vector<int>dis;

void BFS01(int sc){
    deque<int>dq;
    dis[sc]=0;
    dq.push_back(sc);

    while(!dq.empty()){
        int xx = dq.front();
        dq.pop_front();

        for(auto v : g[xx]){
            int nei = v.first;
            int wei = v.second;

            if(dis[nei] > dis[xx] + wei){
                 dis[nei] = dis[xx] + wei;

                 if(wei ==0){
                    dq.push_front(nei);
                 }else{
                    dq.push_back(nei);
                 }
            }
        }
    }
}

void solve(){
    cin>>n>>m;
    g.clear();
    g.resize(n+1);
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back({y, 0});
        g[y].push_back({x, 1});
    }
    dis.assign(n+1, 1e9);

    BFS01(1);

    if(dis[n]>=1e9) dis[n]=-1;

    cout<<dis[n]<<"\n";
}

int main(){
    int t;
    cin>>t;
    while(t--)
    solve();
}
