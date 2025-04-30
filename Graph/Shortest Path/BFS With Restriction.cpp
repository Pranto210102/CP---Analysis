#include<bits/stdc++.h>
using namespace std;
#define F first 
#define S second 
const int inf =1e9;
vector<string>arr;

int n,m,k;
int dx[]= {0,1,0,-1};
int dy[]= {1,0,-1,0};
using state = pair<pair<int,int>, int>;

bool inside(int x, int y){
   if(x>=0 && x<n && y>=0 && y<m) return 1;
   return 0;
}

vector<vector<vector<int>>>dis, vis;

void bfs(pair<int,int> st){
     vis = vector<vector<vector<int>>>(
         n, vector<vector<int>>(
             m, vector<int>(
                k+1, 0
            )
          )
        );
     dis = vector<vector<vector<int>>>(
        n, vector<vector<int>>(
            m, vector<int>(
                k+1, inf
            )
            )
        );
        
      queue<state>q;
      dis[st.F][st.S][0]=0;
      q.push({st, 0});  

      while(!q.empty()){
         state cur = q.front(); q.pop();
         // process once
         if(vis[cur.F.F][cur.F.S][cur.S])continue;
         vis[cur.F.F][cur.F.S][cur.S]=1;
         // process  the node
         for(int dir=0; dir<4; dir++){
            int nx= cur.F.F + dx[dir];
            int ny= cur.F.S + dy[dir];

            if(inside(nx, ny)){ // valid check
                int nw = cur.S + (arr[nx][ny]=='#'? 1: 0);
                if(nw>k) continue;
                if(dis[nx][ny][nw]>dis[cur.F.F][cur.F.S][cur.S] +1){
                    dis[nx][ny][nw]=dis[cur.F.F][cur.F.S][cur.S] +1;
                    q.push({{nx, ny}, nw});
                }
            }
         }
      }
}

int main(){
    cin>>n>>m>>k;
    arr.resize(n+1);
    pair<int,int>st, en;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        for(int j=0;j<m;j++){
            if(arr[i][j]=='S')st={i,j};
            else if(arr[i][j]=='E')en={i,j};
        }
    }

    bfs(st);

    for(int i=0;i<=k;i++){
        cout<<i<<" : "<<dis[en.F][en.S][i]<<"\n";
    }


}
