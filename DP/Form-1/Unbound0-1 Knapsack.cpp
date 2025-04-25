#include<bits/stdc++.h>
using namespace std;
int w[3030];
int v[3030];
int dp[3030][3030];
int n;
int W;

int rec(int i, int x){
    if(i==n){
       return 0;
    }

    if(dp[i][x]!=-1) return dp[i][x];

    int notTake = rec(i+1, x);

    int take=0;
    if(w[i]<=x){
        take = rec(i, x-w[i]) + v[i];
    }

    return dp[i][x] = max(take, notTake);
}

int main(){
    cin>>n>>W;
    for(int i=0;i<n;i++)cin>>w[i];
    for(int i=0;i<n;i++)cin>>v[i];

    memset(dp, -1, sizeof(dp));

    int ans = rec(0, W);
    cout<<ans<<"\n";
}
