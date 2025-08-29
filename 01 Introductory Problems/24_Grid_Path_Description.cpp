#include <bits/stdc++.h>
using namespace std;

// 0.98s on C++ 20 lmaooo

// DLUR
int dir[] = {1, 0, -1, 0, 1};
string dirs = "DLUR";

static constexpr int n = 7;
int vis[n][n]{};

bool isBorder(int r, int c){
    return r>=n || r<0 || c>=n || c<0 || vis[r][c];
}

vector<string> a;

string curr;
void dfs(int r, int c, int d, int rem){
    if(rem==1){
        curr.push_back(dirs[d]);
        a.push_back(curr);
        curr.pop_back();
        return;
    }
    if(r==n-1 && c==0) return;

    if(rem!=n*n) curr.push_back(dirs[d]);
    vis[r][c] = 1;
    int ld = (d+1)%4, rd = (d+3)%4;
    bool lb = isBorder(r+dir[ld], c+dir[ld+1]);
    bool rb = isBorder(r+dir[rd], c+dir[rd+1]);
    if(isBorder(r+dir[d], c+dir[d+1])){
        if(lb && !rb) dfs(r+dir[rd], c+dir[rd+1], rd, rem-1);
        if(rb && !lb) dfs(r+dir[ld], c+dir[ld+1], ld, rem-1);  
    }
    else{
        dfs(r+dir[d], c+dir[d+1], d, rem-1);
        if(!rb) dfs(r+dir[rd], c+dir[rd+1], rd, rem-1);
        if(!lb) dfs(r+dir[ld], c+dir[ld+1], ld, rem-1);
    }
    vis[r][c] = 0;
    if(rem!=n*n) curr.pop_back();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    
    auto check = [&](string &x){
        for(int i = 0; i<48; i++){
            if(s[i]=='?') continue;
            if(s[i]!=x[i]) return false;
        }
        return true;
    };

    dfs(0, 0, 0, n*n);

    int res = 0;
    for(string &t:a){
        res += check(t);
    }
    cout<<res;
    
    return 0;
}
