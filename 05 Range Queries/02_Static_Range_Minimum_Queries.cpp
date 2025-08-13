#include <bits/stdc++.h>
using namespace std;

struct SparseTable {
    vector<vector<int>> table;

    // Change
    int merge(int a, int b){
        return min(a, b);
    }

    void build(const vector<int> &arr) {
        int n = arr.size();
        int maxLog = __lg(n) + 1;

        table.assign(n, vector<int>(maxLog));

        for (int i = 0; i<n; i++) {
            table[i][0] = arr[i];
        }

        for (int j = 1; j<maxLog; j++) {
            for (int i = 0; i + (1<<j) <= n; i++) {
                table[i][j] = merge(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    SparseTable(const vector<int>& arr) {
        build(arr);
    }

    int query(int l, int r) {
        int j = __lg(r - l + 1);
        return merge(table[l][j], table[r - (1<<j) + 1][j]);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    SparseTable st(a);

    while(q--){
        int l, r;
        cin>>l>>r;
        l--;
        r--;
        cout<<st.query(l, r)<<'\n';
    }
    
    return 0;
}
