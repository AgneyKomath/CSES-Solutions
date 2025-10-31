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

    int sr = -1, sc = -1;
    for(int i = 0; i < n && sr == -1; i++){
        for(int j = 0; j < n && sr == -1; j++){
            if(a[i][j] == 'A'){
                sr = i, sc = j;
            }
        }
    }

    queue<pair<int, int>> q;
    vector<vector<int>> prev(n, vector<int>(m, -1));
    q.emplace(sr, sc);
    a[sr][sc] = '#';

    while(!q.empty()){
        auto [r, c] = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nr = r + dir[i], nc = c + dir[i + 1];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m || a[nr][nc] == '#') continue;
            prev[nr][nc] = i;

            if(a[nr][nc] == 'B'){
                string path;
                while(prev[nr][nc] != -1){
                    int d = prev[nr][nc];
                    path.push_back(dirs[d]);
                    nr -= dir[d], nc -= dir[d + 1];
                }
                reverse(path.begin(), path.end());
                cout<<"YES\n";
                cout<<path.size()<<'\n';
                cout<<path;
                return 0;
            }

            a[nr][nc] = '#';
            q.emplace(nr, nc);
        }
    }

    cout<<"NO";

    return 0;
}
