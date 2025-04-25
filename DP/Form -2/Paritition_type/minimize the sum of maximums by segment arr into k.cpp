#include<bits/stdc++.h>
using namespace std;
int n,k;
int arr[1010];
int dp[101][101];


int rec(int i, int x){
    //pruning
    if(x<0){
        return 1e9;
    }
    //base case
    if(i==-1){
        if(x==0) return 0;
        else return 1e9;
    }

    // catch check
    if(dp[i][x]!=-1) return dp[i][x];

    // transition
    int ans= 1e9;
    int mx_seen=arr[i];
    for(int j=i-1;j>=-1;j--){
        ans = min(ans, rec(j, x-1) + mx_seen);
        mx_seen=max(mx_seen, arr[j]);
    }

    return  dp[i][x] = ans;
}

int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    memset(dp, -1, sizeof(dp));

    int ans=rec(n-1,k);
    cout<<ans<<"\n";
}
