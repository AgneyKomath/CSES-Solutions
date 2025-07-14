#include <bits/stdc++.h>
using namespace std;
 
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    for(auto &[x,y]:a) cin>>x>>y;
    
    sort(a.begin(),a.end());
    
    int curr=0,score=0;
    for(auto &[x,y]:a){
        curr += x;
        score += y-curr;
    }
    
    cout<<score<<'\n';
    
    return 0;
}