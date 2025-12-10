#include <bits/stdc++.h>
using namespace std;

int block_size, n, q;
vector<int> a, freq;
int dist_cnt;

struct Query {
    int l, r, idx;
};
vector<Query> queries;
bool mo_cmp(Query a, Query b) {
    int block_a = a.l / block_size;
    int block_b = b.l / block_size;
    if (block_a == block_b) { return a.r < b.r; }
    return block_a < block_b;
};
inline void add(int idx) {
    freq[a[idx]]++;
    if(freq[a[idx]] == 1) {
        dist_cnt++;
    }
}
inline void remove(int idx) {
    freq[a[idx]]--;
    if(freq[a[idx]] == 0) {
        dist_cnt--;
    }
}
signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    dist_cnt = 0;
    cin >> n >> q;
    a.resize(n);
    freq.resize(n + 5);
    queries.resize(q);
    block_size = (int)sqrt(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> comp = a;
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for(int i = 0; i < n; i++) {
        a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
    }
    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        queries[i].l = x;
        queries[i].r = y;
        queries[i].idx = i;
    }
    sort(queries.begin(), queries.end(), mo_cmp);

    vector<int> ans(q);

    int cur_l = 0, cur_r = -1;
    for(auto &qr : queries) {
        int l = qr.l;
        int r = qr.r;

        // Expand right
        while(cur_r < r) add(++cur_r);

        // Shrink right
        while(cur_r > r) remove(cur_r--);

        // Shrink left
        while(cur_l < l) remove(cur_l++);

        // Expand left
        while(cur_l > l) add(--cur_l);

        ans[qr.idx] = dist_cnt;
    }

    for(auto & it : ans)
    cout << it << "\n";
    cout << "\n";
}
