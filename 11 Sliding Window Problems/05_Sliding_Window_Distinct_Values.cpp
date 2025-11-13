#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    vector<int> a(n);
    for(int &i : a) cin>>i;

    vector<int> b(a);
    sort(b.begin(), b.end());

    vector<int> mp(n, 0);
    for(int i = 0, cnt = 0; i < n; i++){
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        cnt += ++mp[a[i]] == 1;
        if(i >= k - 1){
            cout<<cnt<<' ';
            cnt -= --mp[a[i - k + 1]] == 0;
        }
    }

    return 0;
}
