#include <bits/stdc++.h>
using namespace std;

int dir[] = {1, 0, -1, 0, 1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<string> a(n);
    for(auto &i:a) cin>>i;

    auto dfs = [&](int r, int c, auto &&dfs){
        if(r<0 || r>=n || c<0 || c>=m || a[r][c]=='#') return;
        a[r][c] = '#';
        for(int i = 0; i<4; i++){
            dfs(r + dir[i], c + dir[i+1], dfs);
        }
    };

    int res = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(a[i][j]=='.'){
                res++;
                dfs(i, j, dfs);
            }
        }
    }

    cout<<res;

    return 0;
}
