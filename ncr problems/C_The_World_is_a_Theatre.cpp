#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll ncr(ll n, ll r){                          // Compute ncr till n=60, r=30 CF : https://codeforces.com/problemset/problem/131/C?mobile=false
    ll ans=1;
    for(ll i=0;i<min(r, n-r);i++){
        ans*=(n-i);
        ans/=(i+1);
    }

    return ans;
}

int main(){
    ll n,m,t;
    cin>>n>>m>>t;

    ll ans=0;

    for(ll b=4;b<=n;b++){
        for(ll g=1;g<=m;g++){
            if(b+g==t){
                ans += ncr(n,b)*ncr(m,g);
            }
        }
    }

    cout<<ans<<"\n";
}
