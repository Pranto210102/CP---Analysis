#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++)cin>>a[i];

    ll ans=0;

    for(ll j=0; j<30; j++){
        
         vector<ll>pref{1, 0};
         ll s=0;

         for(ll i=0; i<n; i++){
             s^=((a[i]>>j) & 1LL);

             ans += (pref[s^1] * (1LL<<j));

             pref[s]++;
         }
    }

    //ans -= accumulate(a.begin(), a.end(), 0LL);

    cout<<ans<<"\n";
}
