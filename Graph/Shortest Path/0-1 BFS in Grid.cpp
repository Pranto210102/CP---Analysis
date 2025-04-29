#include<bits/stdc++.h>    //One Piece AZ
using namespace std;
int n,m;
int arr[1001][1001];
int dis[1001][1001];
using state =pair<int,int>;

int dx[] = {-1, 1, 0, 0};
int dy[] = { 0, 0, -1, 1};


bool is_valid(int x, int y){
    if(x>=1 && x<=n && y>=1 && y<=m) return 1;
    return 0;
}

bool is_right_dec(int xg, int yg, int xm, int ym){
       if(arr[xm][ym]==1 && xg==xm && ym+1== yg) return 1;
       if(arr[xm][ym]==2 && xg==xm && ym-1== yg) return 1;
       if(arr[xm][ym]==3 && xg==1+xm && ym== yg) return 1;
       if(arr[xm][ym]==4 && xg==xm-1 && ym== yg) return 1;

       return 0;
}


void BFS01(int sx, int sy){
     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dis[i][j]=1e9;
        }
     }

     deque<state>dq;
     dq.push_back({sx, sy});
     dis[sx][sy]=0;

     while(!dq.empty()){
         state cur = dq.front();
         dq.pop_front();

         for(int k=0;k<4;k++){
            int nx = cur.first + dx[k];
            int ny = cur.second+ dy[k];
            int weight=0;
            if(is_valid(nx, ny)){

            if(!is_right_dec(nx, ny, cur.first, cur.second))weight=1;

               if(dis[nx][ny]> dis[cur.first][cur.second] + weight){
                  dis[nx][ny] = dis[cur.first][cur.second] + weight;
                 
                  if(weight==0){
                    dq.push_front({nx, ny});
                  }else{
                    dq.push_back({nx, ny});
                 }
              }
            }
         }
     }
}



int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }

    BFS01(1,1);

    cout<<dis[n][m]<<"\n";
}
