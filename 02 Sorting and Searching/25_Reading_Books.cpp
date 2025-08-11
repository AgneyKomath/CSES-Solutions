#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    long long sum = 0, mx = 0;
    for(int i = 0; i<n; i++){
        long long v;
        cin>>v;
        sum += v;
        mx = max(mx, v);
    }

    cout<<max(sum, 2*mx);

    return 0;
}
