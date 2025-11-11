class Solution {                                                              // leetcode : 3725
public:
    using ll = long long;
    ll MXN = 200;
    const ll  mod = 1e9 + 7;

    int countCoprime(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<ll> val(MXN+1, 1);

        for(int k = 0; k < n; k++) {
            
            vector<ll> cnt(MXN+1), cnt2(MXN+1);

            for(ll i = 0; i < m; i++) {
                cnt[mat[k][i]]++;
            }

            for (ll i = 1; i <= MXN; i++) {
                for (ll j = i; j <= MXN; j += i) {
                    cnt2[i] += cnt[j];
                }
            }

            for(int i = 1; i <= MXN; i++) {
                val[i] = (val[i] * cnt2[i]) % mod;
            }
        }

         for(ll i = MXN; i >=1; i--) {
            for(ll j = 2 * i; j <= MXN; j+=i) {
                val[i] = (val[i] - val[j] + mod) % mod;
            }
        }

        return val[1];
    }
};
