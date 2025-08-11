#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    auto check = [&](long long val)->bool{
        int cnt = 1;
        long long curr = 0;
        for(int i:a){
            if(curr + i > val){
                curr = i;
                cnt++;
            }
            else curr += i;
        }
        return cnt<=k;
    };

    long long lo = *max_element(a.begin(), a.end()), hi = 2e14;
    while(lo<hi){
        long long mid = (lo + hi) / 2;
        if(check(mid)) hi = mid;
        else lo = mid+1;
    }

    cout<<hi;
    
    return 0;
}
