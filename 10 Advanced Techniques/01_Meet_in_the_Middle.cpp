#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, x;
    cin>>n>>x;

    vector<int> a(n);
    for(int &i:a) cin>>i;


    auto getSums =[&](int l, int r){
        vector<int> res;
        int n = r-l+1;
        
        for(int i = 0;i<(1<<n); i++){
            int sum = 0;
            for(int j = 0;j<n; j++){
                if(i & (1<<j)) sum += a[l+j];
            }
            res.push_back(sum);
        }
        sort(res.begin(), res.end());
        return res;
    };

    vector<int> left = getSums(0, (n-1)/2);
    vector<int> right = getSums((n+1)/2, n-1);

    int res = 0;

    for(int i:left){
        auto lb = lower_bound(right.begin(), right.end(), x-i);
        auto ub = upper_bound(right.begin(), right.end(), x-i);
        res += ub-lb;
    }

    cout<<res;
    
    
    return 0;
}
