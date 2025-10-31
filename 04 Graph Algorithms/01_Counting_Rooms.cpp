#include <bits/stdc++.h>
using namespace std;

int dir[] = {1, 0, -1, 0, 1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<string> a(n);
    for(auto &i : a) cin>>i;

    auto floodFill = [&](int r, int c){
        queue<pair<int, int>> q;
        q.emplace(r, c);
        a[r][c] = '#';
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + dir[i], nc = c + dir[i + 1];
                if(nr < 0 || nr >= n || nc < 0 || nc >= m || a[nr][nc] == '#') continue;
                a[nr][nc] = '#';
                q.emplace(nr, nc);
            }
        }
    };

    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == '.'){
                res++;
                floodFill(i, j);
            }
        }
    }

    cout<<res;

    return 0;
}
