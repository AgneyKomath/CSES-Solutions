#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin>>n>>k;
    
    auto stringToInt=[&](string &s){
        int res = 0;
        for(int i = 0; i<k; i++){
            if(s[i]=='1'){
                res |= (1<<i);
            }
        }
        return res;
    };

    vector<int> a(n);
    for(int i = 0; i<n; i++){
        string s;
        cin>>s;
        a[i] = stringToInt(s);
    }

    int res = k;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            int d = __builtin_popcount(a[i]^a[j]);
            res = min(res, d);
        }
    }
    cout<<res;
    
    return 0;
}
