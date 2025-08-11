#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin>>n>>t;
    
    vector<int> a(n);
    for(int &i:a) cin>>i;

    auto check = [&](long long val)->bool{
        long long total = 0;
        for(int i:a){
            total += val/i;
            if(total>=t) return true;
        }
        return false;
    };

    long long lo = 0, hi = 1e18;
    while(lo<hi){
        long long mid = (lo + hi) / 2;
        if(check(mid)) hi = mid;
        else lo = mid + 1;
    }
    
    cout<<hi;

    return 0;
}
