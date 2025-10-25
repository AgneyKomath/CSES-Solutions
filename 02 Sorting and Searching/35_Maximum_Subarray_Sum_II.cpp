#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b;
    cin>>n>>a>>b;

    vector<int> x(n);
    for(int &i : x) cin>>i;

    vector<long long> pref(n + 1);
    pref[0] = 0;

    multiset<long long> st;

    long long res = -1e18;
    for(int i = 0; i < n; i++){
        pref[i + 1] = pref[i] + x[i];
        if(i + 1 >= a) st.insert(pref[i + 1 - a]);
        if(!st.empty()) res = max(res, pref[i + 1] - *st.begin());
        if(i + 1 >= b) st.extract(pref[i + 1 - b]);
    }

    cout<<res;

    return 0;
}
