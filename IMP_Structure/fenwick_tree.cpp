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
