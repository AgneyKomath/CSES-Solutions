#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin>>n>>x;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    int res = 0;
    for(int i = 0, j = 0, curr = 0; j < n; j++){
        curr += a[j];
        while(curr > x) curr -= a[i++];
        res += (curr == x); 
    }

    cout<<res;

    return 0;
}
