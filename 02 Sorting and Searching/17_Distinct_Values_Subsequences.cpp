#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    sort(a.begin(), a.end());

    int mod = 1e9 + 7;

    long long res = 1;
    for(int i = 1, cnt = 1; i <= n; i++){
        if(i == n || a[i] != a[i - 1]){
            // Each number you have 1 + cnt choices. Either take any one of them or take none
            res = res * (1 + cnt) % mod;
            cnt = 1;
        }
        else cnt++;
    }

    // Remove Empty Subsequence
    cout<<res - 1;

    return 0;
}
