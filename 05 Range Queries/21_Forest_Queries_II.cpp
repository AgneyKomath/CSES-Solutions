#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BIT2D{
    int n, m;
    vector<vector<T>> tree, a;

    BIT2D(int _n, int _m){
        n = _n;
        m = _m;
        a.assign(n, vector<T>(m, 0));
        tree.assign(n + 1, vector<T>(m + 1, 0));
    }

    BIT2D(vector<vector<T>> arr){
        n = arr.size(), m = arr[0].size();
        tree.assign(n + 1, vector<T>(m + 1, 0));
        a.assign(n, vector<T>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                add(i, j, a[i][j]);
            }
        }
    }

    void add(int r, int c, T v){
        a[r][c] += v;
        for(int i = r + 1; i <= n; i += i&-i){
            for(int j = c + 1; j <= m; j += j&-j){
                tree[i][j] += v;
            }
        }
    }

    void set(int r, int c, T v){
        T diff = v - a[r][c];
        add(r, c, diff);
    }

    void toggle(int r, int c){
        if(a[r][c] == 0) add(r, c, 1);
        else add(r, c, -1);
    }

    T query(int r, int c){
        T sum = 0;
        for(int i = r + 1; i > 0; i -= i&-i){
            for(int j = c + 1; j > 0; j -= j&-j){
                sum += tree[i][j];
            }
        }
        return sum;
    }

    T query(int r1, int c1, int r2, int c2){
        return query(r2, c2) - query(r1 - 1, c2) - query(r2, c1 - 1) + query(r1 - 1, c1 - 1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    vector<string> a(n);
    for(auto &i : a) cin>>i;

    BIT2D<int> bit(n, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == '*') bit.toggle(i, j);
        }
    }

    while(q--){
        int t;
        cin>>t;
        if(t == 1){
            int r, c;
            cin>>r>>c;
            r--, c--;
            bit.toggle(r, c);
        }
        else{
            int r1, c1, r2, c2;
            cin>>r1>>c1>>r2>>c2;
            r1--, c1--, r2--, c2--;
            cout<<bit.query(r1, c1, r2, c2)<<'\n';
        }
    }

    return 0;
}
