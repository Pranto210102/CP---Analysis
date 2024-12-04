#include<bits/stdc++.h>       // https://www.codechef.com/problems/SORT_THEM?tab=statement
using namespace std;

void solve(){
   int n;
   cin>>n;
    string s;
    cin>>s;
 
    string str;
    cin>>str;
    vector<int>tmp(26);
    for(int i=0;i<26;i++){
        int x=str[i]-'a';
        tmp[x]=i+1;
    }

    vector<vector<int>>dp(n, vector<int>(2, 1e9));

    dp[0][0]=0;
    dp[0][1]=1;

    for(int i=1;i<n;i++){

        if(s[i]>=s[i-1]){
            dp[i][0]=dp[i-1][0];
        }

        if(s[i]>= str[27 - tmp[s[i-1]-'a'] -1]){
             
              dp[i][0]=min(dp[i-1][1], dp[i][0]);
        }

         if(s[i-1]<= str[27 - tmp[s[i]-'a'] -1]){
              
              dp[i][1] = 1 + dp[i-1][0];
         }

         if(str[27 - tmp[s[i-1]-'a'] -1]<= str[27 - tmp[s[i]-'a'] -1]){
              
              dp[i][1] =min(dp[i][1], 1 + dp[i-1][1]);
         }
    }

    int ans=min(dp[n-1][0], dp[n-1][1]);

    if(ans>n){
        cout<<-1<<"\n";
        return;
    }

    cout<<ans<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--)
    solve();
}
