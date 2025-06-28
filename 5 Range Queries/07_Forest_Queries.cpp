#include <bits/stdc++.h>
#define int	long long
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,q;
    cin>>n>>q;

    vector<vector<int>> mp(n+1,vector<int>(n+1,0));
    char c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>c;
            mp[i][j] = (c=='*') + mp[i-1][j] + mp[i][j-1] - mp[i-1][j-1];
        }
    }

    while(q--){
        int x1,x2,y1,y2;
        cin>>y1>>x1>>y2>>x2;

        int res = mp[y2][x2] -mp[y1-1][x2] - mp[y2][x1-1] + mp[y1-1][x1-1];
        cout<<res<<'\n';
    }
    
    
    return 0;
}
