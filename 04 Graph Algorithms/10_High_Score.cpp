#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin>>n>>m;

    vector<tuple<int,int,int>> edges(m);

    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        a--;b--;
        edges[i] = {a,b,-w};
    }

    vector<int> dist(n,INF);
    dist[0] = 0;

    for(int i=0;i<n-1;i++){
        bool flag = false;
        for(auto [a,b,w]: edges){
            if(dist[b]>dist[a] + w){
                dist[b] = dist[a] + w;
                flag = true;
            }
        }

        if(!flag) break;
    }

    for(int i=0;i<n-1;i++){
        for(auto [a,b,w]: edges){
            if(dist[b]>dist[a] + w){
                dist[b] = dist[a] + w;
                if(b==n-1){
                    cout<<"-1\n";
                    return 0;
                }
            }
        }
    }

    for(auto i:dist) cout<<i<<' ';
    cout<<'\n';

    cout<<-dist[n-1]<<'\n';
    
    
    return 0;
}
