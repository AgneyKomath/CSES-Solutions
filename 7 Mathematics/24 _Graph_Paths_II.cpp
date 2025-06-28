#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 2e18;

vector<vector<int>> multiply(vector<vector<int>> &a, vector<vector<int>> &b){
    int n = a.size(), w = b.size(), m = b[0].size();
    vector<vector<int>> res(n, vector<int>(m, INF));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            for(int k = 0; k<w; k++){
                res[i][j] = min(res[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    return res;
}

vector<vector<int>> power(vector<vector<int>> &a, int b){
    int n = a.size();
    vector<vector<int>> res(n, vector<int>(n, INF));
    for(int i = 0; i<n; i++) res[i][i] = 0;
    for(; b>0; b /= 2, a=multiply(a, a)){
        if(b&1) res = multiply(res, a); 
    }
    return res;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<int>> base(n, vector<int>(n, INF));
    for(int i = 0; i<m; i++){
        int u, v, c;
        cin>>u>>v>>c;
        u--;v--;
        base[u][v] = min(base[u][v], c);
    }

    auto res = power(base, k);
    
    int ans = (res[0][n-1]==INF?-1:res[0][n-1]);

    cout<<ans;
    
    return 0;
}
