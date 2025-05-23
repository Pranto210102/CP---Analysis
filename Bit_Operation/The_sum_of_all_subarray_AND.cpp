#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
vector<ll>arr;

ll sum_of_all_subarray_AND() {
    ll total_sum = 0;

    for (ll j = 0; j < 32; j++) {
        ll cnt = 0;
        ll sum = 0;

        for (ll i = 0; i < n; i++) {
            if (arr[i] & (1LL << j)) {
                cnt++;
                sum += cnt;
            } else {
                cnt = 0;
            }
        }

        total_sum += (sum * (1LL << j));
    }

    return total_sum;
}
int main(){
    cin>>n;
    arr.resize(n);
    for(ll i=0;i<n;i++)cin>>arr[i];

    ll ans =sum_of_all_subarray_AND();

    cout<<ans<<"\n";
}
