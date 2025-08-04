#include<bits/stdc++.h>
using namespace std;               // count odd even problem.....
using ll = long long;

struct Node {
   int even, odd;
};

vector<Node> tree;
vector<int> a;

void build(int node, int start, int end) {
    if(start == end) {
        if(a[start] & 1) {
            tree[node].odd = 1;
            tree[node].even = 0;
        }
        else {
            tree[node].odd = 0;
            tree[node].even = 1;
        }
        return;
    }

    int mid = (start + end) / 2;
    // left node 
    build(2*node, start, mid);
    // right node
    build(2*node + 1, mid + 1, end);
    
    // merge
    tree[node].even = tree[2 * node].even + tree[2 * node + 1].even;
    tree[node].odd = tree[2 * node].odd + tree[2 * node + 1].odd;
}

void update(int node, int start, int end, int i, int x) {
    if(start == end) {
        // leaf node
        a[i] = x;

        if(a[i] & 1) {
            tree[node].odd = 1;
            tree[node].even = 0;
        }
        else {
            tree[node].odd = 0;
            tree[node].even = 1;
        }
        return;
        
    }
    int mid = (start + end) / 2;

    if(i <= mid) update(2 * node, start, mid, i, x);
    else update(2 * node + 1, mid + 1, end, i, x);

    tree[node].even = tree[2 * node].even + tree[2 * node + 1].even;
    tree[node].odd = tree[2 * node].odd + tree[2 * node + 1].odd;
}

ll Odd_query(int node, int start, int end, int l, int r) {
    if(start >= l && end <= r) {
        return tree[node].odd;
    }
    if(start > r || end < l) {
        return 0;
    }

    int mid = (start + end) / 2;

    return Odd_query(2 * node, start, mid , l , r) +
      Odd_query(2 * node + 1, mid + 1, end, l, r);
}

ll Even_query(int node, int start, int end, int l, int r) {
    if(start >= l && end <= r) {
        return tree[node].even;
    }
    if(start > r || end < l) {
        return 0;
    }

    int mid = (start + end) / 2;

    return Even_query(2 * node, start, mid , l , r) +
      Even_query(2 * node + 1, mid + 1, end, l, r);
}

signed main () {
     int n;
     cin >> n;
     a.resize(n);
     tree.resize(4*n);

     for(int i = 0; i < n; i++) cin >> a[i];

     build(1, 0, n-1);

     int q;
     cin >> q;

     while (q--) {
        int t;
        cin >> t;
        if(t == 0) {
            int i, x;
            cin >> i >> x;
            i--;

            update(1, 0 , n-1, i, x);
        }else if( t == 1){
            int l , r;
            cin >> l >> r;
            l--;
            r--;

            cout << Even_query(1, 0, n-1, l, r) << "\n";
        }else {
            int l , r;
            cin >> l >> r;
            l--;
            r--;

            cout << Odd_query(1, 0, n-1, l, r) << "\n";
        }
     }

}
