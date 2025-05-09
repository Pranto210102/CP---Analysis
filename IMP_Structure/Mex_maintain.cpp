struct MEX {
    set<int> missing;
    map<int, int> freq;
    vector<int> a;

    MEX(const vector<int>& arr) : a(arr) {
        int n = a.size();
        for (int i = 0; i <= n + 1; ++i) missing.insert(i);
        for (int x : a) insert(x);
    }

    void insert(int x) {
        if (x < 0 || x > a.size() + 1) return;
        freq[x]++;
        if (freq[x] == 1) missing.erase(x);
    }

    void remove(int x) {
        if (x < 0 || x > a.size() + 1) return;
        freq[x]--;
        if (freq[x] == 0) missing.insert(x);
    }

    int get() {
        return *missing.begin();
    }
};

struct MEX2 {
    map<int, int> freq;
    int cur_mex = 0;

    void insert(int x) {
        freq[x]++;
        while (freq[cur_mex]) ++cur_mex;
    }

    int get() {
        return cur_mex;
    }

    void clear() {
        freq.clear();
        cur_mex = 0;
    }
};
