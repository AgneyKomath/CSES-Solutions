#include <bits/stdc++.h>
using namespace std;

int dir[] = {1, 0, -1, 0, 1};
string dirs = "DLUR";

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<string> a(n);
    for(auto &i : a) cin>>i;

    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));

    int sr = -1, sc = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'A'){
                sr = i, sc = j;
            }
            else if(a[i][j] == 'M'){
                q.emplace(i, j);
                dist[i][j] = 0;
            }
        }
    }

    while(!q.empty()){
        auto [r, c] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nr = r + dir[i], nc = c + dir[i + 1];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m || a[nr][nc] == '#' || dist[nr][nc] <= dist[r][c] + 1) continue;
            dist[nr][nc] = dist[r][c] + 1;
            q.emplace(nr, nc);
        }
    }

    vector<vector<int>> prev(n, vector<int>(m, -1));
    q.emplace(sr, sc);
    a[sr][sc] = '#';

    int d = 0;
    while(!q.empty()){
        d++;
        int sz = q.size();
        while(sz--){
            auto [r, c] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + dir[i], nc = c + dir[i + 1];
    
                if(nr < 0 || nr >= n || nc < 0 || nc >= m){
                    string path;
                    while(prev[r][c] != -1){
                        int d = prev[r][c];
                        path.push_back(dirs[d]);
                        r -= dir[d], c -= dir[d + 1];
                    }
                    reverse(path.begin(), path.end());
                    cout<<"YES\n";
                    cout<<path.size()<<'\n';
                    cout<<path;
                    return 0;
                }

                if(a[nr][nc] == '#' || dist[nr][nc] <= d) continue;
                prev[nr][nc] = i;
                a[nr][nc] = '#';
                q.emplace(nr, nc);
            }
        }
    }

    cout<<"NO";

    return 0;
}
