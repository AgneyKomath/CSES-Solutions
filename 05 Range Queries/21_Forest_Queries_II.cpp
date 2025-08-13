#include <bits/stdc++.h>
using namespace std;

struct BIT{
    int n;
    vector<vector<int>> tree;

    BIT(int _n){
        n = _n;
        tree.assign(n+1, vector<int>(n+1, 0));
    }

    void add(int r, int c, int v){
        for(int i = r+1; i<=n; i+=i&-i){
            for(int j = c+1; j<=n; j+=j&-j){
                tree[i][j] += v;
            }
        }
    }

    int query(int r, int c){
        int sum = 0;
        for(int i = r+1; i; i-=i&-i){
            for(int j = c+1; j; j-=j&-j){
                sum += tree[i][j];
            }
        }
        return sum;
    }

    int query(int r1, int c1, int r2, int c2){
        return query(r2, c2) - query(r1-1, c2) - query(r2, c1-1) + query(r1-1, c1-1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    vector<string> a(n);
    for(auto &i:a) cin>>i;

    BIT bit(n);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(a[i][j]=='*'){
                bit.add(i, j, 1);
            }
        }
    }

    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int r, c;
            cin>>r>>c;
            r--;c--;
            if(a[r][c]=='*'){
                a[r][c] = '.';
                bit.add(r, c, -1);
            }
            else{
                a[r][c] = '*';
                bit.add(r, c, 1);
            }
        }
        else if(t==2){
            int r1, c1, r2, c2;
            cin>>r1>>c1>>r2>>c2;
            r1--;c1--;r2--;c2--;
            cout<<bit.query(r1, c1, r2, c2)<<'\n';
        }
    }
    
    return 0;
}
