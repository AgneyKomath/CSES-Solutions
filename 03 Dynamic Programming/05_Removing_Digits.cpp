// DP Solution
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> dp(n + 1, 1e6);
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        int x = i;
        while(x){
            int d = x % 10;
            dp[i] = min(dp[i], 1 + dp[i - d]);
            x /= 10;
        }
    }

    cout<<dp[n];

    return 0;
}

// // Greedy Solution
// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n;
//     cin>>n;

//     int res = 0;
//     while(n){
//         int x = n, mxd = 0;
//         while(x){
//             mxd = max(mxd, x % 10);
//             x /= 10;
//         }
//         n -= mxd;
//         res++;
//     }

//     cout<<res;

//     return 0;
// }
