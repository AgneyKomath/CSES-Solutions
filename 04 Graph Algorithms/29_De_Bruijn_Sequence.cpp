#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    if(n == 1){
        cout<<"01";
        return 0;
    }

    n--;

    vector<vector<int>> adj(1 << n);
    for(int i = 0; i < (1 << n); i++){
        int v = i;
        if((v >> (n - 1)) & 1) v ^= 1 << (n - 1);
        v <<= 1;
        adj[i].push_back(v);
        adj[i].push_back(v | 1);
    }
    
    // Hierholzer's algorithm
    string path(n, '0');
    auto dfs = [&](int u, auto &&dfs)->void{
        while(!adj[u].empty()){
            auto v = adj[u].back();
            adj[u].pop_back();
            path += (v & 1) + '0';
            dfs(v, dfs);
        }
    };

    dfs(0, dfs);

    cout<<path;
    
    return 0;
}
