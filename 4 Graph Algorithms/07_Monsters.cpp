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

    vector<vector<int>> dist(n, vector<int>(m, 1e9));

    int ar, ac;

    queue<pair<int, int>> q;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(a[i][j]=='M'){
                q.emplace(i, j);
                dist[i][j] = 0;
            }
            if(a[i][j]=='A'){
                ar = i;
                ac = j;
            }
        }
    }

    while(!q.empty()){
        auto [r, c] = q.front();
        q.pop();
        for(int i = 0; i<4; i++){
            int nr = r + dir[i];
            int nc = c + dir[i+1];
            if(nr<0 || nr>=n || nc<0 || nc>=m || a[nr][nc]=='#' || dist[nr][nc]<=1+dist[r][c]) continue;
            dist[nr][nc] = 1 + dist[r][c];
            q.emplace(nr, nc);
        }
    }

    string path;
    bool pathfound = false;

    vector<vector<pair<int, int>>> prev(n, vector<pair<int, int>>(m, {-1, -1}));
    int d = 0;
    q.emplace(ar, ac);
    prev[ar][ac] = {ar, ac};
    while(!q.empty() && !pathfound){
        d++;
        int sz = q.size();
        while(sz--){
            auto [r, c] = q.front();
            q.pop();

            if(r==0 || r==n-1 || c==0 || c==m-1){
                pathfound = true;
                while(r != ar || c != ac){
                    auto [pr, pc] = prev[r][c];

                    int dr = r - pr, dc = c - pc;
                    if(dr==1) path += 'D';
                    else if(dr==-1) path += 'U';
                    else if(dc==1) path += 'R';
                    else if(dc==-1) path += 'L';

                    tie(r, c) = prev[r][c];
                }
                break;
            }

            for(int i = 0; i<4; i++){
                int nr = r + dir[i];
                int nc = c + dir[i+1];
                if(nr<0 || nr>=n || nc<0 || nc>=m || a[nr][nc]=='#' || dist[nr][nc]<=d|| prev[nr][nc].first != -1) continue;
                prev[nr][nc] = {r, c};
                q.emplace(nr, nc);
            }
        }
    }

    if(!pathfound){
        cout<<"NO";
    }
    else{
        cout<<"YES\n";
        int sz = path.size();
        cout<<sz<<'\n';
        for(int i = sz-1; i>=0; i--) cout<<path[i];
    }
    
    return 0;
}
