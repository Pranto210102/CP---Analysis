#include<bits/stdc++.h> //AtCoder Regular Contest 135 (C)
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];

    vector<ll>cnt1(31, 0),cnt0(31,0); // count 0's and 1's for all bit position

    for(ll i=0;i<n;i++){
        for(ll j=0;j<31;j++){
            if(a[i] & (1<<j)){
                cnt1[j]++;
            }else{
                cnt0[j]++;
            }
        }
    }
    ll mx=0LL;

    for(ll i=0;i<n;i++){               // compute all xor value with each element and update mx for each element.

        ll pos_xor=0LL;

        for(ll j=0LL;j<31LL;j++){
            
            if(a[i] & (1LL<<j)){
                pos_xor += cnt0[j]*(1LL<<j);
            }else{
                pos_xor +=cnt1[j]*(1LL<<j);
            }

            mx=max(mx, pos_xor);
        }
    }

    ll pos_xor=0LL;       // for zero opration

        for(ll j=0LL;j<31LL;j++){
            
            if(0LL & (1LL<<j)){
                pos_xor += cnt0[j]*(1LL<<j);
            }else{
                pos_xor +=cnt1[j]*(1LL<<j);
            }

            mx=max(mx, pos_xor);
        }

    cout<<mx<<"\n";
}
