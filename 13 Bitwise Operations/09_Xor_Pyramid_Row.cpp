#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    int diff = n - k;

    for(int b = (1 << 20); b; b >>= 1){
        if(!(diff & b)) continue;
        int nn = n - b;
        vector<int> na(nn);
        for(int i = 0; i < nn; i++){
            int l = a[i], r = (i + b < n ? a[i + b] : 0);
            na[i] = l ^ r;
        }
        swap(a, na);
        swap(n, nn);
    }

    for(int i : a) cout<<i<<' ';

    return 0;
}