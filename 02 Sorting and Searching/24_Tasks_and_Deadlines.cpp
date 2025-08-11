#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<pair<int, int>> a(n);
    for(auto &[x, y]:a) cin>>x>>y;
    
    sort(a.begin(), a.end());
    
    int curr = 0, res = 0;
    for(auto &[x, y]:a){
        curr += x;
        res += y-curr;
    }
    
    cout<<res;
    
    return 0;
}