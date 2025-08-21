#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin>>n>>x;
    
    vector<int> a(n);
    for(int &i:a) cin>>i;

    auto subsetSum = [&](int l, int r){
        int sz = r-l+1;
        int len = 1<<sz;
        vector<long long> res(len, 0);
        for(int i = 0; i<len; i++){
            for(int j = 0; j<sz; j++){
                if(i&(1<<j)) res[i] += a[j+l];
            }
        }
        sort(res.begin(), res.end());
        return res;
    };
    
    vector<long long> left = subsetSum(0, (n-1)/2);
    vector<long long> right = subsetSum((n+1)/2, n-1);

    long long res = 0;
    for(auto i:left){
        int lb = lower_bound(right.begin(), right.end(), x-i) - right.begin();
        int ub = upper_bound(right.begin(), right.end(), x-i) - right.begin();
        res += ub-lb;
    }

    cout<<res;
    
    return 0;
}
