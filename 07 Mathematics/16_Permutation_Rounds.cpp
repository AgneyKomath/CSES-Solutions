#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> p(n);
    for(int &i : p){
        cin>>i;
        i--;
    }

    map<int, int> mp;
    vector<int> vis(n, 0);
    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        int curr = i;
        int sz = 0;
        while(!vis[curr]){
            vis[curr] = 1;
            sz++;
            curr = p[curr];
        }
        
        for(int i = 2; i * i <= sz; i++){
            if(sz % i == 0){
                int curr = 0;
                while(sz % i == 0){
                    curr++;
                    sz /= i;
                }
                mp[i] = max(mp[i], curr);
            }
        }
        if(sz > 1){
            mp[sz] = max(mp[sz], 1);
        }
    }

    const int mod = 1e9 + 7;
    long long res = 1;
    for(auto [k, v] : mp){
        for(int i = 0; i < v; i++){
            res = res * k % mod;
        }
    }

    cout<<res;

    return 0;
}
