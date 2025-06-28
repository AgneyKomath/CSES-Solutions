#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,m,q;
    cin>>n>>m>>q;
    
    vector<vector<int>> dist(n,vector<int>(n,1e18));
    for(int i=0;i<n;i++) dist[i][i] = 0;

    for(int i=0;i<m;i++){
        int a,b,d;
        cin>>a>>b>>d;
        a--;b--;
        dist[a][b] = min(dist[a][b],d);
        dist[b][a] = min(dist[b][a],d);
    }
    
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){   
            for(int j=0;j<n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]); 
            }
        }
    }

    while(q--){
        int a,b;
        cin>>a>>b;
        a--;b--;

        cout<<(dist[a][b]==1e18?-1:dist[a][b])<<'\n';
    }
    
    return 0;
}
