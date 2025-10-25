#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int mx = 0;
    long long sum = 0;
    for(int i = 0; i < n; i++){
        int v;
        cin>>v;
        sum += v;
        mx = max(mx, v);
    }

    cout<<max(2ll * mx, sum);

    return 0;
}
