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

    int n,k;
    cin>>n>>k;

    vector<pair<int,int>> a(n);
    for(auto &[e,s]:a) cin>>s>>e;

    sort(a.begin(),a.end());

    multiset<int> st;

    int res=0;
    for(auto &[e,s]:a){
        if(st.empty()){
            st.insert(e);
            res++;
            continue;
        }
        auto it = st.upper_bound(s);
        if(it!=st.begin()){
            it = prev(it);
            st.erase(it);
            st.insert(e);
            res++;
        }
        else{
            if(st.size()<k){
                st.insert(e);
                res++;
            }
        }
    }

    cout<<res<<'\n';
    
    return 0;
}
