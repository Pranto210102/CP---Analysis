#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string L, R;
ll D, len;
const ll mod = 1e9 + 7;

ll dp[10010][2][2][100];


ll rec(ll level, ll tlo, ll thi, ll sum) {
    if(level == len) {
        if(sum == 0) return 1;
        return 0;
    }

    if(dp[level][tlo][thi][sum] != -1) return dp[level][tlo][thi][sum];

    ll lo = 0;
    if(tlo == 1) {
        lo = L[level] - '0';
    }
    ll high = 9;
    if(thi == 1) {
        high = R[level] - '0';
    }

    ll ans = 0;

    for(ll i = lo; i <= high; i++) {
        ll nlo = tlo;
        if(i != L[level] - '0') nlo = 0;
        ll nhi = thi;
        if(i != R[level] - '0') nhi = 0;

        (ans += rec(level + 1, nlo, nhi, (sum + i) % D)) %= mod;
    }

    return dp[level][tlo][thi][sum] = ans;
}

void solve() {
    L = "1";
    cin >> R >> D;
    ll cnt = R.length() - L.length();
    string tmp;
    while(cnt--) {
        tmp += '0';
    }
    
    L = tmp + L;
    len = R.size();
    memset(dp, -1, sizeof(dp));
    cout << rec(0, 1, 1, 0) << "\n";
}


signed main() {
    solve();
}
