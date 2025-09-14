#include <bits/stdc++.h>
using namespace std;

vector<int> g[100100];
int parent[100100];
int dep[100100];
bool is_leaf[100100];
int subtreeSz[100100];
int childNum[100100];

void dfs(int node, int par, int depth) {
    parent[node] = par;
    dep[node] = depth;
    subtreeSz[node] = 1;

    for(auto v : g[node]) {
        if(v != par) {
            childNum[node]++;
            dfs(v, node, depth + 1);
            subtreeSz[node] += subtreeSz[v];
        }
    }
    if(childNum[node] == 0) {
        is_leaf[node] = 1;
    }
}

signed main() {
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, 0, 0);

    for(int i = 1; i <= n; i++) {
        cout << "node = " << i << " ";
        cout << "parent = " << parent[i] << " ";
        cout << "depth = " << dep[i] << " ";
        cout << "is_leaf = " << is_leaf[i] << " ";
        cout << "subtree size = " << subtreeSz[i] << " ";
        cout << "child num = " << childNum[i] << "\n";  
    }


}
