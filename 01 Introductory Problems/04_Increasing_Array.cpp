#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    long long res = 0;
    for(int i = 0, prev = 0; i < n; i++){
        int v;
        cin>>v;
        prev = max(prev, v);
        res += prev - v;
    }

    cout<<res;

    return 0;
}
