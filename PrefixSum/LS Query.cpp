#include <bits/stdc++.h>
using namespace std;                      // Focus on right modular arithmetic to handle negetive sum .
#define ll long long
#define mod 1000000007
void solve(){
    ll n,q;
    cin>>n>>q;
     vector<ll> a(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    for(ll i=1;i<n;i++){
        a[i]= (a[i]+ a[i-1])%mod;
        if(a[i]<0)        // handle negetive sum
        a[i]+=mod;
    }

    while(q--){
        ll l, r;
        cin>>l>>r;
        l--;
        r--;
        if(l==0){
            cout<<(a[r] + mod) %mod<<"\n";
        }else{
            cout<<(a[r]-a[l-1]+mod)%mod<<"\n";       // + mod 
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	  int t=1;
      //cin>>t;
      while(t--)
      solve();

}
