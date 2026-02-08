#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin>>u>>v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto dfs = [&](int u, int p, auto &&dfs)->pair<int, int>{        
        int curr = 0, bestDiff = 0;
        for(int v : adj[u]){
            if(v == p) continue;
            auto [notChosen, chosen] = dfs(v, u, dfs);
            curr += notChosen;
            bestDiff = max(bestDiff, 1 + chosen - notChosen);
        }
        return {curr + bestDiff, curr};
    };
    cout<<dfs(0, -1, dfs).first;

    return 0;
}
