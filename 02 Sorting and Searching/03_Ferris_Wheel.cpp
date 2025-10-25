#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin>>n>>x;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    sort(a.begin(), a.end());

    int res = 0;
    for(int l = 0, r = n - 1; l <= r; r--){
        if(a[l] + a[r] <= x) l++;
        res++;
    }

    cout<<res;

    return 0;
}
