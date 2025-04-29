#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<pair<int,int>>g[100100];
int dis[100100];

void BFS01(int sc){
    deque<int>dq;
    for(int i=1;i<=n;i++){
        dis[i]=1e9;
    }

    dis[sc]=0;
    dq.push_back(sc);
    while(!dq.empty()){
         int xx = dq.front();
         dq.pop_front();

         for(auto v : g[xx]){
            int neigh = v.first;
            int weigh = v.second;

            if(dis[neigh]>dis[xx]){
                dis[neigh]= dis[xx] + weigh;

                if(weigh==0){
                    dq.push_front(neigh);
                }else{
                    dq.push_back(neigh);
                }
            }
         }
    }
}


int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    int sc;
    cin>>sc;

    BFS01(sc);

    // sc to all node sortest path
}
