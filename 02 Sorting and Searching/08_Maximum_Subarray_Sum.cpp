#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    long long res = -1e9, curr = 0;
    for(int i : a){
        curr += i;
        res = max(res, curr);
        curr = max(curr, 0ll);
    }

    cout<<res;

    return 0;
}
