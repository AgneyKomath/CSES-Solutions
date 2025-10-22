// Bitset Approach
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    bitset<100001> bts = 1;
    
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        bts |= bts << x;
    }

    cout<<bts.count() - 1<<'\n';
    for(int i = 1; i <= 100000; i++){
        if(bts[i]) cout<<i<<' ';
    }

    return 0;
}

// // Normal DP Approach
// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n;
//     cin>>n;

//     vector<int> a(n);
//     int sum = 0;
//     for(int &i : a){
//         cin>>i;
//         sum += i;
//     }

//     vector<bool> dp(sum + 1, 0);
//     dp[0] = 1;
//     for(int i : a){
//         for(int j = sum; j >= i; j--){
//             dp[j] = dp[j] || dp[j - i];
//         }
//     }

//     int res = count(dp.begin(), dp.end(), 1) - 1;
//     cout<<res<<'\n';
//     for(int i = 1; i <= sum; i++){
//         if(dp[i]) cout<<i<<' ';
//     }

//     return 0;
// }

