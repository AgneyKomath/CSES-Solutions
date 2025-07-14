#include <bits/stdc++.h>
using namespace std;

int dir[] = {1, 0, -1, 0, 1};
map<pair<int, int>, char> mp{
    {{-1, 0}, 'U'},
    {{1, 0}, 'D'},
    {{0, -1}, 'L'},
    {{0, 1}, 'R'}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<string> a(n);
    for(auto &i:a) cin>>i;

    queue<pair<int, int>> q;
    vector<vector<pair<int, int>>> prev(n, vector<pair<int, int>>(m, {-1, -1}));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(a[i][j]=='A'){
                q.emplace(i, j);
                a[i][j] = '#';
            }
        }
    }

    string path;

    while(!q.empty() && path.empty()){
        auto [r, c] = q.front();
        q.pop();
        for(int i = 0; i<4; i++){
            int nr = r + dir[i], nc = c + dir[i+1];
            if(nr<0 || nr>=n || nc<0 || nc>=m || a[nr][nc]=='#') continue;
            prev[nr][nc] = {r, c};
            if(a[nr][nc]=='B'){
                int cr = nr, cc = nc;
                while(prev[cr][cc].first != -1){
                    auto [pr, pc] = prev[cr][cc];
                    int dr = cr - pr, dc = cc - pc;
                    path += mp[{dr, dc}];
                    cr = pr;
                    cc = pc;
                }
                break;
            }
            a[nr][nc] = '#';
            q.emplace(nr, nc);
        }
    }

    if(path.empty()){
        cout<<"NO";
    }
    else{
        cout<<"YES\n";
        reverse(path.begin(), path.end());
        cout<<path.size()<<'\n';
        cout<<path;
    }

    return 0;
}
