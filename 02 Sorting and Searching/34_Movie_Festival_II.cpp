#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;

    vector<pair<int, int>> a(n);
    for(auto &[e, s] : a) cin>>s>>e;

    sort(a.begin(), a.end());

    multiset<int> st;
    for(int i = 0; i < k; i++) st.insert(i);

    int res = 0;
    for(auto [e, s] : a){
        auto it = st.upper_bound(s);
        if(it == st.begin()) continue;
        res++;
        st.erase(--it);
        st.insert(e);
    }

    cout<<res;

    return 0;
}
