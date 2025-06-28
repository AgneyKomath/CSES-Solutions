#include <bits/stdc++.h>
#define int	long long
using namespace std;

const int dr[] = {1,-1,0,0};
const int dc[] = {0,0,1,-1};

map<pair<int,int>,char> mp{
    {{-1,0},'U'},
    {{1,0},'D'},
    {{0,-1},'L'},
    {{0,1},'R'}
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int n,m;
    cin>>n>>m;

    int Ar,Ac,Br,Bc;

    vector<string> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<m;j++){
            if(a[i][j]=='A'){
                Ar = i;
                Ac = j;
            }
            if(a[i][j]=='B'){
                Br = i;
                Bc = j;
            }
        }
    }

    vector<vector<bool>> visited(n,vector<bool>(m,0));
    vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m,{-1,-1}));
    queue<pair<int,int>> q;

    q.push({Ar,Ac});
    visited[Ar][Ac] = 1;


    while(!q.empty()){
        auto [r,c] = q.front();
        q.pop();
        if(r==Br && c==Bc) break;
        for(int i=0;i<4;i++){
            int nr = r+dr[i], nc = c+dc[i];
            if(nr<0||nr>=n||nc<0||nc>=m||a[nr][nc]=='#'||visited[nr][nc]) continue;
            visited[nr][nc] = 1;
            parent[nr][nc] = {r,c};
            q.push({nr,nc});
        }
    }

    if(!visited[Br][Bc]){
        cout<<"NO\n";
        return 0;
    }

    string path;
    while(!(Br==Ar && Bc==Ac)){
        auto [r,c] = parent[Br][Bc];
        path.push_back(mp[{Br-r,Bc-c}]);
        Br = r;
        Bc = c;
    }
    reverse(path.begin(),path.end());

    cout<<"YES\n"<<path.size()<<'\n'<<path;    
    
    return 0;
}
