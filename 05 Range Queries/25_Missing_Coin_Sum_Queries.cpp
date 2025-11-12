#include <bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

static constexpr int MXN = 2e5, LOG = 31;
static int tree[2 * MXN][LOG], a[MXN], tres[LOG];
static long long pref[MXN + 1][LOG], pres[LOG];

// Iterative Segment Tree
void build(int n){
    for(int j = 0; j < LOG; j++) pref[0][j] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < LOG; j++){
            pref[i + 1][j] = pref[i][j];
            tree[n + i][j] = (1 << j) + 1;
        }
        int b = a[i] == 1 ? 0 : 1 + __lg(a[i] - 1);
        tree[n + i][b] = a[i];
        pref[i + 1][b] += a[i];
    }
    for(int i = n - 1; i > 0; i--){
        for(int j = 0; j < LOG; j++){
            tree[i][j] = min(tree[i << 1][j], tree[i << 1 | 1][j]);
        }
    }
}

void tquery(int l, int r, int n){
    for(int j = 0; j < LOG; j++) tres[j] = INT_MAX;
    for(l += n, r += n + 1; l < r; l >>= 1, r >>= 1){
        if(l & 1){
            for(int j = 0; j < LOG; j++){
                tres[j] = min(tres[j], tree[l][j]);
            }
            l++;
        }
        if(r & 1){
            --r;
            for(int j = 0; j < LOG; j++){
                tres[j] = min(tres[j], tree[r][j]);
            }
        }
    }
}

void pquery(int l, int r){
    for(int j = 0; j < LOG; j++){
        pres[j] = pref[r + 1][j] - pref[l][j];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    for(int i = 0; i < n; i++) cin>>a[i];

    build(n);

    while(q--){
        int l, r;
        cin>>l>>r;
        l--, r--;

        tquery(l, r, n);
        pquery(l, r);

        long long curr = 1;
        for(int i = 0; i <= 30; i++){
            if(tres[i] > curr) break;
            curr += pres[i];
        }
        cout<<curr<<'\n';
    }

    return 0;
}
