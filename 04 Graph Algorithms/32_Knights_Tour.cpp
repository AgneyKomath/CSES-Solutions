#include <bits/stdc++.h>
using namespace std;

static const int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
static const int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};
static const int n = 8;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin>>x>>y;
    x--, y--;

    vector<vector<vector<pair<int, int>>>> adj(n, vector<vector<pair<int, int>>>(n));
    vector<vector<int>> rem(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < 8; k++){
                int r = i + dr[k], c = j + dc[k];
                if(r < 0 || r >= n || c < 0 || c >= n) continue;
                adj[i][j].emplace_back(r, c);
                rem[i][j]++;
            }
        }
    }

    vector<vector<int>> res(n, vector<int>(n, -1));
    auto f = [&](int r, int c, int t, auto &&f)->bool{
        if(t == n * n) return true;

        // Crazy Heuristic
        for(auto [nr, nc] : adj[r][c]) rem[nr][nc]--;
        sort(adj[r][c].begin(), adj[r][c].end(), [&](auto &p1, auto &p2){
            return rem[p1.first][p1.second] < rem[p2.first][p2.second];
        });

        for(auto [nr, nc] : adj[r][c]){
            if(res[nr][nc] != -1) continue;
            res[nr][nc] = t;
            if(f(nr, nc, t + 1, f)) return true;
            res[nr][nc] = -1;
        }
        
        for(auto [nr, nc] : adj[r][c]) rem[nr][nc]++;
        return false;
    };
    
    res[y][x] = 0;
    f(y, x, 1, f);

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<res[i][j] + 1<<' ';
        }
        cout<<'\n';
    }
    
    return 0;
}
