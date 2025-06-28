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
    
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n);

    while(m--){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(n,-1);
    stack<pair<int,int>> st;
    vector<bool> visited(n,0);

    for(int node =0;node<n;node++){
        if(visited[node]) continue;
        st.push({node,-1});
        visited[node] = 1;
    
        while(!st.empty()){  
            auto [tp,par] = st.top();
            st.pop();
    
            visited[tp] = 1;
            parent[tp] = par;
            
            for(int i :adj[tp]){
                if(i == parent[tp]) continue;
                
                if(visited[i]){
                    vector<int> res;
                    res.push_back(i);
                    while(tp!=-1 && tp!=i){
                        res.push_back(tp);
                        tp = parent[tp];
                    }
                    res.push_back(i);
                    cout<<res.size()<<'\n';
                    for(auto i:res) cout<<i+1<<' ';
                    return 0;
                }
                st.push({i,tp});
            }
        }
    }

    cout<<"IMPOSSIBLE\n";

    
    return 0;
}
