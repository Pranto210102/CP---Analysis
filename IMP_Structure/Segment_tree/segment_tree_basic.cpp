#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 ll n, q;
vector<ll> a;

struct node{
     ll sum;
     node(){
        sum = 0;
     }
};
vector<node> tree;

node merge(node &a, node &b) {
    node ans;
    ans.sum = (a.sum + b.sum);
    return ans;
}

void build(ll id, ll l, ll r){
     if(l == r) {
        tree[id].sum = a[l];
        return;
     }

     ll mid = (l + r) / 2;

     build(2*id, l, mid);
     build(2*id + 1, mid + 1, r);

     tree[id] = merge(tree[2*id] , tree[2*id + 1]);
}

void update(ll id, ll l , ll r, ll pos, ll val){
     if(pos < l || pos > r) return;

     if(l == r) {
        tree[id].sum = val;
        a[l] = val;
        return;
     }

    ll mid = (l + r) / 2;

     update(2*id, l, mid, pos, val);
     update(2*id + 1, mid + 1, r, pos, val);

     tree[id] = merge(tree[2*id] , tree[2*id + 1]);
}

node query(ll id, ll l, ll r, ll lq, ll rq) {
     if(lq > r || rq < l) return node();

     if(lq <= l && rq >= r) return tree[id];

     ll mid = (l + r) / 2;

    node left =  query(2*id, l, mid, lq, rq);
    node right =  query(2*id + 1, mid + 1, r, lq, rq);

    return merge(left, right);
}

signed main() {
    cin >> n >> q;
    a.resize(n);
    tree.resize(4*n);
    for(ll i = 0; i < n; i++) cin >> a[i];

    build(1, 0, n-1);

    while(q--) {
        ll t;
        cin >> t;
        if(t == 2) {
            ll lq, rq;
            cin >> lq >> rq;
            lq--;
            rq--;

          node x =  query(1, 0, n-1, lq, rq);

           cout << x.sum << "\n";
        }else {
            ll pos, val;
            cin >> pos >> val;
            pos--;

            update(1, 0, n-1, pos, val);
        }
    }

}
