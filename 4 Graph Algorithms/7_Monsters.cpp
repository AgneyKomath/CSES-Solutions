#include <bits/stdc++.h>
#define int long long
using namespace std;

int dr[4]{1,-1,0,0};
int dc[4]{0,0,1,-1};

map<pair<int,int>,char> mp{
    {{1,0},'D'},
    {{0,1},'R'},
    {{-1,0},'U'},
    {{0,-1},'L'}
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin>>n>>m;
    vector<string> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int x = -1, y =-1;

    queue<array<int,3>> q;

    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(a[i][j]=='M'){
                q.push({i,j,0});
                a[i][j] = '#';
            } 
            if(a[i][j]=='A'){
                x = i;
                y = j;
                a[i][j] = '#';
            }
        }
    }
   vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m,{-1,-1}));

    q.push({x,y,1});
    while(!q.empty()){
        auto [r, c, t] = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr<0||nc<0||nr>=n||nc>=m){
                if(t==1){
                    cout<<"YES\n";
                    string path;
                    while(parent[r][c] != make_pair(-1ll, -1ll)){
                        auto [pr,pc] = parent[r][c];
                        path.push_back(mp[{r-pr,c-pc}]);
                        tie(r,c) = parent[r][c];
                    }
                    reverse(path.begin(), path.end());
                    cout<<path.size()<<'\n';
                    cout<<path;
                    return 0;
                }
                continue;
            }
            if(a[nr][nc]=='#') continue;
            if(t==1){
                parent[nr][nc] = {r,c};
            }
            a[nr][nc] = '#';
            q.push({nr,nc,t});
        }
    }

    cout<<"NO\n";
    
    
    return 0;
}
