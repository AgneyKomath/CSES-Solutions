#include <bits/stdc++.h>
#define int	long long
using namespace std;

int mxn = 1e6;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    vector<int> divisors(mxn+1,0);

    for(int i=1;i<=mxn;i++){
        for(int j = i;j<=mxn;j+=i){
            divisors[j]++;
        }
    }
    int n,x;
    cin>>n;
    while(n--){
        cin>>x;
        cout<<divisors[x]<<'\n';
    }
    
    return 0;
}


// int mxn = 1e6;

// vector<int> minp, primes;
// void sieve(int n) {
//     minp.assign(n + 1, 0);
//     primes.clear();
//     for (int i = 2; i <= n; i++) {
//         if (minp[i] == 0) {
//             minp[i] = i;
//             primes.push_back(i);
//         }
//         for (auto p : primes) {
//             if (i * p > n) break;
//             minp[i * p] = p;
//             if (p == minp[i]) break;
//         }
//     }
// }

// int32_t main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     #ifdef Fusion15
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif

//     sieve(1e6);

//     vector<unordered_map<int,int>> factors(mxn+1);

//     for(int i:primes){
//         int power = 1;
//         int val = i;
//         while(val<=mxn){
//             for(int j = val;j<=mxn;j+=val){
//                 factors[j][i] = power;
//             }
//             power++;
//             val *= i;
//         }
//     }


//     int n,x;cin>>n;
//     while(n--){
//         cin>>x;
//         int res = 1;
//         for(auto &[k,v]:factors[x]){
//             // cout<<k<<": "<<v<<"   ";
//             res *= (v+1);
//         }
//         // cout<<'\n';
//         cout<<res<<'\n';
//         // cout<<'\n';
//     }
    
//     return 0;
// }
