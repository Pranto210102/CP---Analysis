#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct hasher{
    ll base,mod;
    vector<ll>hash, basepow,revhash;
    hasher(){

    }
    hasher(string s, ll _base, ll _mod){
        base=_base, mod=_mod;
        ll n=s.size();
        hash.resize(n+1); basepow.resize(n+1);
        hash[0]=0; basepow[0]=1;

        for(ll i=1;i<=n;i++){
            hash[i] = ((hash[i-1]*base)%mod + (s[i-1]-'a' +1))%mod;
            basepow[i] = (basepow[i-1]*base) %mod;
        }

        // reverse
        revhash.resize(n+1);
        revhash[n]=0;
        for(ll i=n-1;i>=0;i--){
            revhash[i] = ((revhash[i+1]*base)%mod + (s[i]-'a' +1))%mod;
        }
    }

    ll gethash(ll l, ll r){ // 0 indexed..O(1)
         ll ans = (hash[r+1]-(hash[l]*basepow[r-l+1])%mod)%mod;
         return (ans + mod)%mod;
    }
    // reverse hash
    ll getrevhash(ll l, ll r) {
        ll ans = (revhash[l] - (revhash[r + 1] * basepow[r - l + 1]) % mod + mod) % mod;
        return ans;
    }
};
struct doublehasher{
     hasher h1, h2;
     doublehasher(){}
     doublehasher(string s){
         h1 = hasher(s, 37, 999999929LL);
         h2 = hasher(s, 41, 999999937LL);
     }
     pair<ll,ll>gethash(ll l, ll r){
        return {h1.gethash(l, r), h2.gethash(l, r)};
     }
     pair<ll,ll>getrevhash(ll l, ll r){
        return {h1.getrevhash(l, r), h2.getrevhash(l, r)};
     }
};
