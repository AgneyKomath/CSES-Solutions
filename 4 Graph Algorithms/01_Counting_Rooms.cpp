#include <bits/stdc++.h>
#define int	long long
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin>>n>>m;

    vector<string> a(n);
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    auto dfs=[&](int i, int j, auto &self)->void{
        if(i<0||i>=n||j<0||j>=m||a[i][j]=='#') return;
        a[i][j]='#';
        self(i+1,j,self);
        self(i,j+1,self);
        self(i-1,j,self);
        self(i,j-1,self);
    };

    int cnt=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='.'){
                cnt++;
                dfs(i,j,dfs);
            }
        }
    }

    cout<<cnt;

    return 0;
}
