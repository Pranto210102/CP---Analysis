#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MXN 200001                          // https://atcoder.jp/contests/abc342/tasks/abc342_d

ll spf[MXN +1];

void pre() {
    for(ll i = 0; i <= MXN; i++) {
        spf[i] = i;
    }
    for(ll i = 2; i <= MXN; i++) {
        if(spf[i] == i) {
            for(ll j = 2 * i; j <= MXN; j+= i) {
                if(spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

map<ll,ll> get_factor_map(ll x) {
    map<ll,ll> mp;
    while(x != 1) {
        mp[spf[x]]++;
        x /= spf[x];
    }
    return mp;
}

pair<ll,ll> reduce_and_comp(ll x) {
     if(x == 1) return {1, 1};
    auto mp = get_factor_map(x);
    ll red = 1;
    ll com = 1;

    for(auto v : mp) {
        if(v.second % 2 == 0) continue;

        else if(v.second % 2 == 1) {
            red *= v.first;
            com *= v.first;
        }
    }
    return {red, com};
}

signed main() {
    pre();
    ll n;
    cin >> n;
    ll arr[n];
    ll ans = 0;
    ll cnt_zero = 0;
    map<ll,ll> mp;
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] == 0) {
            cnt_zero++;
            continue;
        }
        auto tmp = reduce_and_comp(arr[i]);
        ans += mp[tmp.second];
        mp[tmp.second]++;
    }

    cout << ans + (cnt_zero * (n - cnt_zero)) + (cnt_zero * (cnt_zero - 1)) / 2 << "\n";

}
