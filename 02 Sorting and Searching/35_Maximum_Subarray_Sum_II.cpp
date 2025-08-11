#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, r;
    cin>>n>>l>>r;

    vector<int> a(n);
    for(int &i:a) cin>>i;

    vector<long long> pref(n+1);
    pref[0] = 0;

    long long res = -1e18;

    multiset<long long> st;
    for(int i = 0; i<n; i++){
        pref[i+1] = pref[i] + a[i];
        if(i+1>=l) st.insert(pref[i+1-l]);
        if(!st.empty()) res = max(res, pref[i+1] - *st.begin());
        if(i+1>=r) st.erase(st.find(pref[i+1-r]));
    }

    cout<<res;
    
    return 0;
}
