#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    // Bitmask Approach
    // One represents a tile that is open at the bottom
    // Zero represents everything else. left facing, right facing, top facing

    int len = 1 << n;
    auto check = [&](int x) ->int{
        // Zeros represent horizontal tiles
        // Hence all runs of zeroes must be even
        // Distance between ones must be even
        int prev = -1;
        for(int j = 0; j < n; j++){
            if((x >> j) & 1){
                if((j - prev - 1) & 1) return 0;
                prev = j;
            }
        }
        return ((n - prev - 1) & 1) == 0;
    };

    vector<bool> valid(len, 0);
    for(int i = 0; i < len; i++) valid[i] = check(i);

    // Create Adjacency List of Valid Transitions
    vector<vector<int>> adj(len);
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            // Every downward facing tile must be matched with a upward facing tile
            // Basically a bit cant be one on both masks
            // The number of horizontal tiles can be calculated using (i or j)
            // This is because any vertical tile on either mask will be a 1 
            if((i & j) == 0 &&  valid[i | j]){
                adj[i].push_back(j);
            }
        }
    }

    vector<vector<int>> dp(m, vector<int>(len, 0));
    for(int i = 0; i < len; i++) dp[0][i] = valid[i];
    for(int i = 1; i < m; i++){
        for(int j = 0; j < len; j++){
            for(int k : adj[j]){
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
            }
        }
    }

    cout<<dp[m - 1][0];

    return 0;
}
