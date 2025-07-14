#include <bits/stdc++.h>
#define int	long long
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef Fusion15
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, l, r;
    cin>>n>>l>>r;
    vector<int> pref(n+1,0);

    multiset<int> st;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        pref[i+1] = pref[i] + temp;
    }

    int res = -1e18;
    for(int i=1;i<=n;i++){
        if(i>=l) st.insert(pref[i-l]);
        
        if(!st.empty()){
            int val = pref[i] - *st.begin();
            res = max(res, val);
        }

        if(i>=r) st.erase(st.find(pref[i-r]));
    }

    cout<<res<<'\n';
    
    return 0;
}
