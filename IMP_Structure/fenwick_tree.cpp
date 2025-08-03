struct Fenwick {
    vector<ll> bit;
    ll n;

    Fenwick(ll n) {
        this->n = n;
        bit.assign(n+2, 0);
    }

    void update(ll i, ll val) {
        for(; i <= n; i+= (i & -i))
         bit[i] += val;
    }
    ll sum(ll i) {
        ll s = 0;
        while(i > 0) {
            s +=bit[i];
            i -= (i & (- i));
        }
        return s;
    }
};
// comparission idea
set<ll> u_val(arr.begin(), arr.end());
    map<ll,ll> compressed;
    int idx = 1;
    for(auto it : u_val){
        compressed[it] = idx++;
    }
