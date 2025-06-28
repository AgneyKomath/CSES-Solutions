#include <bits/stdc++.h>
#define int long long
using namespace std;

class BIT{
    //Fenwick Tree by Fusion15
    vector<vector<bool>> arr;
    vector<vector<int>> tree;
    int n;

    void build(){
        for(int i=0;i<n;i++){
            for(int j = 0;j<n;j++){
                add(i, j, arr[i][j]);
            }
        }
    }

    int query(int y, int x){
        int s = 0;
        for(int i = y+1;i>0;i -= i&-i){
            for(int j = x+1; j>0; j -= j&-j){
                s += tree[i][j];
            }
        }
        return s;
    }

public:
    
    BIT(vector<string> &a){
        n = a.size();
        arr.resize(n,vector<bool>(n, 0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(a[i][j]=='*') arr[i][j] = 1;
            }
        }

        tree.resize(n+1,vector<int>(n+1, 0));

        build();
    }

    void add(int y, int x,  int val){
        

        for(int i=y+1;i<=n; i += i&-i){
            for(int j = x+1; j<=n; j += j&-j){
                tree[i][j] += val;
            }
        }
    }

    void update(int y, int x){
        int val;
        if(arr[y][x]){
            arr[y][x] = 0;
            val = -1;
        }
        else{
            arr[y][x] = 1;
            val = 1;
        }
        add(y, x, val);
    }

    int query(int y1, int x1, int y2, int x2){
        return query(y2, x2) - query(y1-1, x2) - query(y2, x1-1) + query(y1-1, x1-1); 
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, q;
    cin>>n>>q;

    vector<string> a(n);
    for(auto &i:a) cin>>i;

    BIT bit(a);

    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int y, x;
            cin>>y>>x;
            y--;
            x--;
            bit.update(y, x);
        }
        else{
            int y1, x1, y2, x2;
            cin>>y1>>x1>>y2>>x2;
            y1--;x1--;y2--;x2--;
            cout<<bit.query(y1, x1, y2, x2)<<'\n';
        }
    }
    
    return 0;
}
