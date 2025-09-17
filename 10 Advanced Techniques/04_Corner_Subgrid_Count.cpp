#include <bits/stdc++.h>

// Doesn't fit within time limit if not included
#pragma GCC target("avx2", "bmi2", "fma") 
#pragma GCC optimize("O3", "unroll-loops", "fast-math") 
#pragma GCC optimize("unroll-loops")            

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;

    bitset<3000> bts[3000];
    for(int i = 0; i<n; i++){
        string s;
        cin>>s;
        bts[i] = bitset<3000>(s);
    }
 
    long long res = 0;
    for(int i = 0; i<n; i++){
        for(int j = i + 1; j<n; j++){
            int v = (bts[i] & bts[j]).count();
            res += v * (v - 1) / 2;
        }
    }
 
    cout<<res;
    
    return 0;
}