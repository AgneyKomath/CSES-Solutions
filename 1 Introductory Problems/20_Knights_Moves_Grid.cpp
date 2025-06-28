#include <bits/stdc++.h>
using namespace std;

static const int dr[] = {1, 2, 2, 1, -1, -2, -2, -1};
static const int dc[] = {2, 1, -1, -2, -2, -1, 1, 2};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<vector<int>> res(n, vector<int>(n, -1));

    res[0][0] = 0;
    queue<pair<int, int>> q;
    q.emplace(0, 0);

    int dist = 1;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            auto [r, c] = q.front();
            q.pop();
            for(int i = 0; i<8; i++){
                int nr = r + dr[i], nc = c + dc[i];
                if(nr<0 || nr>=n || nc<0 || nc>=n || res[nr][nc]!=-1) continue;
                res[nr][nc] = dist;
                q.emplace(nr, nc);
            }
        }
        dist++;
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++) cout<<res[i][j]<<" \n"[j==n-1];
    }
    
    return 0;
}
