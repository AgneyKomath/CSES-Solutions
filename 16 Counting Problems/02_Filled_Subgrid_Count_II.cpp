#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    vector<string> a(n);
    for(auto &i:a) cin>>i;

    vector<vector<int>> height(k, vector<int>(n, 0)), dp(k, vector<int>(n, 0));
    vector<long long> res(k, 0);

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(!i){
                height[a[i][j] - 'A'][j]++;
            }
            else{
                if(a[i][j] == a[i-1][j]){
                    height[a[i][j] - 'A'][j]++;
                }
                else{
                    height[a[i-1][j] - 'A'][j] = 0;
                    height[a[i][j] - 'A'][j]++;
                }
            }
        }
        
        // montonic stack
        vector<vector<int>> st(k, {-1});
        for(int j = 0; j<n; j++){
            int id = a[i][j] - 'A';
            
            if(j && a[i][j] != a[i][j-1]){
                st[id] = {j - 1};
            } 
            while(st[id].back() != -1 && height[id][st[id].back()] >= height[id][j]){
                st[id].pop_back();
            } 
            
            int p = (st[id].back() == -1 ? 0 : dp[id][st[id].back()]);
            dp[id][j] = p + height[id][j] * (j - st[id].back());

            res[id] += dp[id][j];

            st[id].push_back(j);
        }

        for(int j = 0; j<n; j++) dp[a[i][j] - 'A'][j] = 0;
    }
    
    for(long long i:res) cout<<i<<'\n';
    
    return 0;
}
