#include <bits/stdc++.h>
using namespace std;

// Sparse Table that stores rightmost index of max values
struct SparseTable {
    vector<vector<int>> table;
    vector<int> a;

    int merge(int i, int j){
        if(a[i] == a[j]) return i > j ? i : j;
        return a[i] > a[j] ? i : j;
    }

    SparseTable(const vector<int>& arr) {
        a = arr;
        int n = a.size();
        int maxLog = __lg(n) + 1;

        table.assign(n, vector<int>(maxLog));

        for (int i = 0; i < n; i++) {
            table[i][0] = i;
        }

        for (int j = 1; j < maxLog; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                table[i][j] = merge(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r) {
        int j = __lg(r - l + 1);
        return merge(table[l][j], table[r - (1 << j) + 1][j]);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    vector<long long> pref(n + 1, 0);
    for(int i = 0; i < n; i++) pref[i + 1] = pref[i] + a[i];
    auto sumQuery = [&](int l, int r){
        if(l > r) return 0ll;
        return pref[r + 1] - pref[l];
    };

    vector<int> nextGreat(n), stack;
    // Min cost to make suffix at i increasing
    vector<long long> dp(n + 1);
    dp[n] = 0;
    for(int i = n - 1; i >= 0; i--){
        while(!stack.empty() && a[stack.back()] <= a[i]) stack.pop_back();
        nextGreat[i] = stack.empty() ? n : stack.back();
        stack.push_back(i);

        int id = nextGreat[i];
        dp[i] = dp[id] + 1ll * (id - i) * a[i] - sumQuery(i, id - 1);
    }

    SparseTable st(a);

    // O(1) Queries Answer
    while(q--){
        int l, r;
        cin>>l>>r;
        l--, r--;

        // Base Cost is Cost to make Suffix at l increasing
        long long res = dp[l];

        int mxid = st.query(l, r);
        int mx = a[mxid];

        int id = nextGreat[mxid];

        // Remove Contribution from elements after r
        res -= dp[id] + 1ll * (id - r - 1) * mx - sumQuery(r + 1, id - 1);

        cout<<res<<'\n';
    }  

    return 0;
}
