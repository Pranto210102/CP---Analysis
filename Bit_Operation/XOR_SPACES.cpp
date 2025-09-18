 using ll = long long;       // leetcode bi-week 165
    vector<ll> basis;
    void insert_in_basis(ll mask) {
        for(ll i = 61; i >= 0; i--) {
            if((mask & (1LL << i)) == 0) continue;

            if(!basis[i]) {
                basis[i] = mask;
                return;
            }
            mask ^= basis[i];
        }
    }
    int maxXorSubsequences(vector<int>& nums) {
        basis.assign(32,0);
        ll n = nums.size();

        for(int i = 0; i < n; i++) {
            insert_in_basis(nums[i]);
        }

        ll ans = 0;
        for(ll i = 31; i >= 0; i--) {
            if(!basis[i]) continue;
            if((1LL << i) & i) continue;
            ans = max(ans, ans^basis[i]);
        }
        return ans;
    }
