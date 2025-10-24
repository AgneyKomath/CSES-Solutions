#include <bits/stdc++.h>
using namespace std;

int dr[] = {1, 1, 2, 2, -1, -1, -2, -2};
int dc[] = {2, -2, 1, -1, 2, -2, 1, -1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<vector<int>> res(n, vector<int>(n, -1));
    queue<pair<int, int>> q;
    res[0][0] = 0;
    q.emplace(0, 0);

    while(!q.empty()){
        auto [r, c] = q.front();
        q.pop();
        for(int i = 0; i < 8; i++){
            int nr = r + dr[i], nc = c + dc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= n || res[nr][nc] != -1) continue;
            res[nr][nc] = res[r][c] + 1;
            q.emplace(nr, nc); 
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<res[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}
