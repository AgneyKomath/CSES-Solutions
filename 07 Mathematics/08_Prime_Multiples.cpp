#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, k;
    cin>>n>>k;
    
    vector<long long> a(k);
    for(auto &i:a) cin>>i;

    long long INF = 2 * n;
    
    long long res = 0;

    for(int i = 0; i <= (1 << k); i++){

        long long p = 1;
        for(int j = 0; j<k; j++){
            if((i >> j) & 1){
                if(INF / p < a[j]){
                    p = INF;
                    break;
                }
                p *= a[j];
            }
        }
        
        long long cnt = n / p;
        
        res += (__builtin_parity(i) ? 1 : -1) * cnt;
    }

    cout<<res;
    
    return 0;
}
